
#include <string>
#include <iostream>
#include <string>
#include <curl/curl.h>

size_t cb_stdstring(
  void *contents,
  size_t size,
  size_t nmemb,
  std::string *s
)
{
    size_t newLength = size*nmemb;
    try
    {
        s->append((char*)contents, newLength);
    }
    catch(std::bad_alloc &e)
    {
        //handle memory problem
        return 0;
    }
    return newLength;
}

std::string request(
  bool debug,
  std::string path,
  std::map<std::string, std::string> member
) {
  CURL *curl;
  CURLcode res;
 
  struct curl_slist *host = NULL;

  // node1.d.fabco.dappy:443:143.244.205.40
  std::string cached_dns_resolution = member.at("hostname") + ":" + member.at("port") + ":" + member.at("ip");
  char cached_dns_resolution_char[cached_dns_resolution.size() + 1];
  strcpy(cached_dns_resolution_char, cached_dns_resolution.c_str());
  host = curl_slist_append(NULL, cached_dns_resolution_char);

  curl_easy_setopt(curl, CURLOPT_RESOLVE, host);

  /* In windows, this will init the winsock stuff */
  curl_global_init(CURL_GLOBAL_ALL);
 
  /* get a curl handle */
  curl = curl_easy_init();
  std::string s;
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_RESOLVE, host);

    std::string url_string = "https://" + member.at("hostname") + ":" + member.at("port") + path;

    char url_chars[url_string.length() + 1];
    strcpy(url_chars, url_string.c_str());

    curl_easy_setopt(curl, CURLOPT_URL, url_chars);

    // Headers
    struct curl_slist *list = NULL;
    list = curl_slist_append(list, "Content-Type: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);

    // Self signed certificate from dappy network
    char strpem[member.at("caCert").length() + 1];
    strcpy(strpem, member.at("caCert").c_str());
    struct curl_blob blob;
    blob.data = strpem;
    blob.len = strlen(strpem);
    blob.flags = CURL_BLOB_COPY; 
    curl_easy_setopt(curl, CURLOPT_CAINFO_BLOB, &blob);

    // Verify peer with the CA from dappy network
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
    
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 1L);

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cb_stdstring);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);

    if (debug)
      curl_easy_setopt (curl, CURLOPT_VERBOSE, 1L);

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);

    /* Check for errors */
    if(res != CURLE_OK) {
      fprintf(
        stderr, "curl_easy_perform() failed: %s\n",
        curl_easy_strerror(res)
      );
      throw std::string(curl_easy_strerror(res));
    }

    /* always cleanup */
    curl_easy_cleanup(curl);
    //curl_slist_free_all(list);

    if (debug) {
      std::cout<<s<<std::endl;
    }
  }
  curl_global_cleanup();

  return s;
}
