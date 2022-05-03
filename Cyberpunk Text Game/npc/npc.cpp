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
        attitude = jWriter["Attitudes"].value("Angry","");
        Console::setConsoleColor(CC_Yellow);
    }
    else if (this->attitude == Hostile)
    {
        attitude = jWriter["Attitudes"].value("Hostile", "");
        Console::setConsoleColor(CC_Red);
    }
    else if (this->attitude == Friendly)
    {
        attitude = jWriter["Attitudes"].value("Friendly", "");
        Console::setConsoleColor(CC_Green);
    }
    else
    {
        attitude = jWriter["Attitudes"].value("Neutral", "");
        Console::resetConsoleColor();
    }

    Display::write("\t" + this->name + jWriter["Attitudes"].value("Is", "") + attitude + jWriter["Attitudes"].value("Now", ""));
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
    Npc CadensPartner(jWriter["Npcs"].value("Policeman_Name",""), Male, Fraction::fractions["Police"]);
    Npc Zed("Zed", Male, Fraction::fractions["None"]);
    Npc Nyx("Nyx", Female, Fraction::fractions["Sleepers"]);
    Npc Jet(jWriter["Npcs"].value("Bouncer_Name", ""), Male, Fraction::fractions["Hammers"]);
    Npc Vincent("Vincent", Male, Fraction::fractions["Hammers"]);
    Npc Enigma("Enigma", Male, Fraction::fractions["None"]);
    // AKT I
    Npc Morpheus(jWriter["Npcs"].value("Morpheus_Name", ""), Male, Fraction::fractions["Sleepers"]);
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