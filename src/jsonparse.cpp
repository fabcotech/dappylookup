#include <iostream>
#include <iomanip>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

int main()
{
    // JSON text
    char text[] = R"(
     {
         "colors": {
	                "color": "black",
		        "category": "hue",
		        "type": "primary",
	                       "code": {
			        "rgba": [255,255,255,1],
			        "hex": "#000"
			      }
		     }		
     }
     )";

    // parsing and serializing JSON
    json j_complete = json::parse(text);
    std::cout << std::setw(4) << j_complete << endl;
}