#include "npc.hpp"

std::map <std::string, Npc> Npc::npcs;

Npc::Npc()
{
    this->name = "None";
    this->sex = Undefined;
    this->fraction = Fraction();
    this->attitude = Neutral;
    this->status = Normal;
    this->knowingHero = false;
}

Npc::Npc(std::string name, int sex, Fraction fraction)
{
    this->name = name;
    this->sex = sex;
    this->fraction = fraction;
    this->attitude = Neutral;
    this->status = Normal;
    this->knowingHero = false;
}


Npc::Npc(std::string name, int sex, Fraction fraction, int attitude, int status, bool knowingHero)
{
    this->name = name;
    this->sex = sex;
    this->fraction = fraction;
    this->attitude = attitude;
    this->status = status;
    this->knowingHero = knowingHero;
}

Npc::~Npc()
{
}

void Npc::setName(std::string name)
{
    this->name = name;
}

void Npc::setSex(int sex)
{
    this->sex = sex;
}

void Npc::setFraction(Fraction fraction)
{
    this->fraction = fraction;
}

void Npc::setAttitude(int attitude)
{
    this->attitude = attitude;
    printAttitude();
}

void Npc::printAttitude()
{
    std::string attitude;

    if (this->attitude == Angry)
    {
        attitude = JSON::getValue("Attitude_Angry");
        Console::setConsoleColor(CC_Yellow);
    }
    else if (this->attitude == Hostile)
    {
        attitude = JSON::getValue("Attitude_Hostile");
        Console::setConsoleColor(CC_Red);
    }
    else if (this->attitude == Friendly)
    {
        attitude = JSON::getValue("Attitude_Friendly");
        Console::setConsoleColor(CC_Green);
    }
    else
    {
        attitude = JSON::getValue("Attitude_Neutral");
        Console::resetConsoleColor();
    }

    Display::write("\t" + this->name + " is " + attitude + " now.\n");
    Console::resetConsoleColor();
}

bool Npc::isDead()
{
    if (status != Dead) return false;
    return true;
}

void Npc::initNpcs()
{
    Logger::out("Function starts", "Npc::initNpcs");
    // PROLOG
    Npc Bob("Bob", Male, Fraction::fractions["Beggars"]);
    Npc Caden("Caden", Male, Fraction::fractions["Police"]);
    Npc CadensPartner(JSON::getValue("Npc_Policeman_Name"), Male, Fraction::fractions["Police"]);
    Npc Zed("Zed", Male, Fraction::fractions["None"]);
    Npc Nyx("Nyx", Female, Fraction::fractions["Sleepers"]);
    Npc Jet(JSON::getValue("Npc_Bouncer_Name"), Male, Fraction::fractions["Hammers"]);
    Npc Vincent("Vincent", Male, Fraction::fractions["Hammers"]);
    Npc Enigma("Enigma", Male, Fraction::fractions["None"]);
    // AKT I
    Npc Morpheus(JSON::getValue("Npc_Morpheus_Name"), Male, Fraction::fractions["Sleepers"]);
    Npc MerQRy("Mer Q'Ry", Male, Fraction::fractions["None"]);
    Npc Karla("Karla", Female, Fraction::fractions["None"]);
    Npc ChipCaine("Chip Caine", Male, Fraction::fractions["None"]);
    Npc JaxRasac("Jax Rasac", Male, Fraction::fractions["SowersOfConfusion"]);

    npcs["Bob"] = Bob;
    npcs["Caden"] = Caden;
    npcs["CadensPartner"] = CadensPartner;
    npcs["Zed"] = Zed;
    npcs["Nyx"] = Nyx;
    npcs["Jet"] = Jet;
    npcs["Vincent"] = Vincent;
    npcs["Enigma"] = Enigma;
    npcs["Morpheus"] = Morpheus;
    npcs["MerQRy"] = MerQRy;
    npcs["Karla"] = Karla;
    npcs["ChipCaine"] = ChipCaine;
    npcs["JaxRasac"] = JaxRasac;
}