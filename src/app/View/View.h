#ifndef VIEW_H
#define VIEW_H

#include <string>
#include "LCD.h"

#pragma once

enum{CARD_READER, CARD_REGISTER, FOUND_MEMBER};

class View
{
public:
    View(LCD *lcd);
    virtual ~View();
    void GolfMembersInfo(int membersManagerState);
    void cardReader();
    void cardRegister();
    void foundMember();
    void RegisteredMember();
    void RegisteredMemberInfo(std::string name);
    void notRegisteredMember();
    void MemberFound(std::string name);
    void MemberNotFound();
    void MemberRegisterMode();
private:
    LCD *lcd; 
    int membersManagerState;

};

#endif