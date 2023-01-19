// Your First C++ Program

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include "request.cpp"
#include "network.cpp"

std::string coresolution_result(
  bool debug,
  int network_size,
  std::map<std::string, std::string> responses
) {

  int responses_size = 0;
  std::map<std::string, std::string>::iterator it;
  for(it = responses.begin(); it != responses.end(); ++ it){
    responses_size += 1;
  }

  std::map<int, int> absolutes;
  absolutes[1] = 1;
  absolutes[2] = 2;
  absolutes[3] = 2;
  absolutes[4] = 3;
  absolutes[5] = 3;
  absolutes[6] = 4;
  absolutes[7] = 4;

  std::map<int, int> accuracies;
  accuracies[1] = 100;
  accuracies[2] = 100;
  accuracies[3] = 66;
  accuracies[4] = 66;
  accuracies[5] = 66;
  accuracies[6] = 66;
  accuracies[7] = 66;

  if (debug) {
    std::cout << "[should stop] Should we stop co-resolution ?" << std::endl;
    std::cout << "[should stop] Responses at that time : " << responses_size << "/" << network_size << std::endl;
    std::cout << "[should stop] Will check for absolute " << absolutes[network_size] << std::endl;
    std::cout << "[should stop] Will check for accuracy " << accuracies[network_size] << std::endl;
  }

  if (responses_size >= absolutes[network_size]) {
    if (debug)
      std::cout << "[should stop] Absolute reached, co-resolution should be either successful/unsuccessful" << std::endl;

    std::map<std::string, int> counts;
    std::map<std::string, std::string>::iterator it;
    for(it = responses.begin(); it != responses.end(); ++ it){
      if (counts.find(responses[it->first]) == counts.end()) {
        counts[responses[it->first]] = 1;
      } else {
        counts[responses[it->first]] += 1;
      }
    }

    std::map<std::string, int>::iterator it2;
    for(it2 = counts.begin(); it2 != counts.end(); ++ it2){
      float f = it2->second;
      float percent = 100 * (f / responses_size);
      if (debug)
        std::cout << "[should stop] checking for " << (it2->first).substr(0,30) << " => " << it2->second << " -- " << percent << "%" << std::endl;

      if (percent >= accuracies[network_size]) {
        if (debug) {
          std::cout << "[should stop] Found a response over accuracies threshold" << std::endl;
          std::cout << it2->first << std::endl;
        }
        return it2->first;
      }
    }
  } else {
    if (debug)
      std::cout << "Absolute not reached, co-resolution must continue" << std::endl;
  }

  return "continue";
}

int coresolve(
  bool debug,
  std::string record_type,
  std::string name,
  std::string network_id
) {
  if (debug)
    std::cout << "starting co-resolution" << std::endl;

  std::vector<std::map<std::string, std::string>> network = getNetwork(network_id);
  int network_size = network.size();

  if (debug)
    std::cout << network_size << " members" << std::endl;

  std::map<std::string, std::string> responses;

  std::string final_result = "ERR_COULD_NOT_RESOLVE";
  //const std::map<std::string, std::string> responses = {};
  for (int i = 0; i < network_size; i++) {

    if (debug)
      std::cout << "[request no" << i << "]" << std::endl;

    std::cout << network[i].at("hostname") << std::endl;
    std::string response;
    try {
      response = request(
        debug,
        "/" + name + "/" + record_type,
        network[i]
      );
      std::cout << "----- request success" << std::endl;
      std::cout << response.substr(0,40) << std::endl;
      responses[network[i].at("hostname")] = response;
    } catch (std::string err){
      std::cout << "----- request error" << std::endl;
      std::cout << err.substr(0,40) << std::endl;
    }

    std::string a = "[request no" + std::to_string(i) + "]";
    if (debug) {
      std::cout << a << " successful" << std::endl;
      std::cout << a << " status code 200" << std::endl;
      std::cout << response.substr(0, 20) << std::endl;
    }

    std::string should_stop = coresolution_result(debug, network_size, responses);
    if (should_stop != "continue") {
      final_result = should_stop;
      break;
    }
  }

  std::cout << "Final result of co-resolution : " << std::endl;
  std::cout << final_result << std::endl;

  return 0;
}
