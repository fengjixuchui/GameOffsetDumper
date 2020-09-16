#include <iostream>
#include "ConfigReader.h"
#include "Process.h"
#include <optional>

int main()
{
    std::optional<std::string> gameName = ConfigReader::ReadGameName("config.toml");
    if (!gameName) {
        std::cerr << "Specify the name of the target game" << std::endl;
        return 1;
    }
    std::vector<SignatureInfo> configs = ConfigReader::ReadSigs("config.toml");
    for (SignatureInfo& config : configs)
    {
        Process p = Process::GetProcess(*gameName, config.module);
    }
}