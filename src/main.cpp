// Your First C++ Program

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <cargs.h>
#include "coresolve.cpp"

bool debug = false;
bool help = false;
bool version = false;

static struct cag_option options[] = {
  {.identifier = 'd',
   .access_letters = "d",
   .access_name = "debug",
   .value_name = NULL,
   .description = "Run in debug mode with many logs for co-resolution and TLS session"},

  {.identifier = 'v',
   .access_letters = "v",
   .access_name = "version",
   .value_name = NULL,
   .description = "Simple flag"},

  {.identifier = 'n',
    .access_letters = "n",
    .access_name = "name",
    .value_name = "NAME",
    .description = "Name or domain name"},

  {.identifier = 'i',
    .access_letters = "net",
    .access_name = "network",
    .value_name = "NETWORK",
    .description = "ID of the dappy network"},

  {.identifier = 't',
    .access_letters = "t",
    .access_name = "type",
    .value_name = "TYPE",
    .description = "Type of record A / AAAA / TXT / CERT / CNAME"},

  {.identifier = 'h',
    .access_letters = "h",
    .access_name = "help",
    .description = "Shows the command help"}};

struct demo_configuration
{
  bool simple_flag;
  bool multiple_flag;
  bool long_flag;
  const char *type;
  const char *name;
  const char *network;
};

int main(int argc, char** argv) {
  char identifier;
  const char *value;
  cag_option_context context;
  struct demo_configuration config = {false, false, false, NULL, NULL};
  int param_index;

  /**
   * Now we just prepare the context and iterate over all options. Simple!
   */
  cag_option_prepare(&context, options, CAG_ARRAY_SIZE(options), argc, argv);
  while (cag_option_fetch(&context)) {
    identifier = cag_option_get(&context);
    switch (identifier) {
    case 'd':
      debug = true;
      config.simple_flag = true;
      break;
    case 'v':
      version = true;
      config.simple_flag = true;
      break;
    case 'm':
      config.multiple_flag = true;
      break;
    case 'l':
      config.long_flag = true;
      break;
    case 'i':
      value = cag_option_get_value(&context);
      config.network = value;
      break;
    case 'n':
      value = cag_option_get_value(&context);
      config.name = value;
      break;
    case 't':
      value = cag_option_get_value(&context);
      config.type = value;
      break;
    case 'h':
      cag_option_print(options, CAG_ARRAY_SIZE(options), stdout);
      return EXIT_SUCCESS;
    }
  }

  if (debug) {
    printf(
      "type: %s, name: %s, network: %s\n",
      config.type ? config.type : "-",
      config.name ? config.name : "-",
      config.network ? config.network : "-"
    );
  }


  for (param_index = context.index; param_index < argc; ++param_index) {
    printf("additional parameter: %s\n", argv[param_index]);
  }

  if (version) {
    std::cout << "version" << std::endl;
    return 0;
  }

  std::string name;
  if (config.name) {
    name = config.name;
  } else {
    std::cout << std::string("missing --name parameter") << std::endl;
    return 1;
  }

  std::string network_id = "d";
  if (config.network) {
    network_id = config.network;
  }
  if (debug)
    std::cout << "network : " + network_id << std::endl;

  std::string record_type = "A";
  if (config.type) {
    if (
      config.type == std::string("A") ||
      config.type == std::string("AAAA") ||
      config.type == std::string("TXT") ||
      config.type == std::string("CERT") ||
      config.type == std::string("CNAME")
    ) {
      record_type = config.type;
    } else {
      std::cout << std::string("unrecognized --type parameter") << std::endl;
      return 1;
    }
  }

  return coresolve(debug, record_type, name, network_id);
}
