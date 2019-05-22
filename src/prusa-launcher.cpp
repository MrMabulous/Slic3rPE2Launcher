// Just put prusa-launcher.exe into the same folder as prusa-slicer.exe and prusa-slicer-console.exe
// And point "Slic3r Executable" in Repetier-Host's Slicer Manager to prusa-launcher.exe

#include <iostream>
#include <sstream>
#include <algorithm>

bool cmdOptionExists(char** begin, char** end, const std::string& option)
{
	return std::find(begin, end, option) != end;
}

int main(int argc, char * argv[])
{
	std::string executable = argv[0];
	size_t index = executable.find("prusa-launcher.exe", 0);

	std::ostringstream oss;
	oss << "\"";
	if (cmdOptionExists(argv, argv + argc, "--gui"))
	{
		executable.replace(index, 18, "prusa-slicer.exe");
		oss << executable;
		oss << "\"";
	}
	else {
		executable.replace(index, 18, "prusa-slicer-console.exe");
		oss << executable;
		oss << "\"";
		oss << " --export-gcode";
	}

	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "--gui") != 0) {
			oss << " ";
			oss << argv[i];
		}
	}

	return system(oss.str().c_str());
}
