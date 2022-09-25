#include "View.h"
#include <wiringPi.h>
View::View(LCD *lcd)
{
    this->lcd = lcd;
}

View::~View()
{

}


void View::GolfMembersInfo(int membersManagerState)
{
    switch (membersManagerState)
    {
        case CARD_READER:
            cardReader();

        break;
        case CARD_REGISTER:
            cardRegister();

        break;
        case FOUND_MEMBER:
            foundMember();
        
        break;
        case DELETE_MEMBER:
            deleteMember();
        break;

    }            
}

void View::cardReader()
{
    char buff[30];
    sprintf(buff,"Card Reader     ");
    lcd -> WriteStringXY(0,0, buff);
    sprintf(buff,"                   ");
    lcd -> WriteStringXY(1,0, buff);
}

void View::cardRegister()
{
    char buff[30];
    sprintf(buff,"Card Register     ");
    lcd -> WriteStringXY(0,0, buff);
    sprintf(buff,"                   ");
    lcd -> WriteStringXY(1,0, buff);
}

void View::foundMember()
{
    char buff[30];
    sprintf(buff,"Founding Member    ");
    lcd -> WriteStringXY(0,0, buff);
    sprintf(buff,"                   ");
    lcd -> WriteStringXY(1,0, buff);
}

void View::RegisteredMember()
{
    char buff[30];
    sprintf(buff,"Registered!!   ");
    lcd -> WriteStringXY(0,0, buff);
    sprintf(buff,"                   ");
    lcd -> WriteStringXY(1,0, buff);

}

void View::RegisteredMemberInfo(std::string name)
{
    char buff[30];
    sprintf(buff,"Registered!!   ");
    lcd -> WriteStringXY(0,0, buff);
    sprintf(buff,"%s           ", name.c_str());
    lcd -> WriteStringXY(1,0, buff);


}
void View::notRegisteredMember()
{
    char buff[30];
    sprintf(buff,"not Registered!!   ");
    lcd -> WriteStringXY(0,0, buff);
    sprintf(buff,"                   ");
    lcd -> WriteStringXY(1,0, buff);

}
// void View::addRegisteredMember()
// {
//     char buff[30];
//     sprintf(member.name,"not Registered!!   ");
//     lcd -> WriteStringXY(0,0, buff);

// }

void View::MemberFound(std::string name)
{
    char buff[30];
    sprintf(buff,"Founding!!       ");
    lcd -> WriteStringXY(0,0, buff);
    sprintf(buff,"%s           ", name.c_str());
    lcd -> WriteStringXY(1,0, buff);
}

void View::MemberNotFound()
{
    char buff[30];
    sprintf(buff,"Not Found!!      ");
    lcd -> WriteStringXY(0,0, buff);
    sprintf(buff,"                   ");
    lcd -> WriteStringXY(1,0, buff);
}

void View::MemberRegisterMode()
{
    char buff[30];
    sprintf(buff,"Type inform!!     ");
    lcd -> WriteStringXY(0,0, buff);
    sprintf(buff,"                   ");
    lcd -> WriteStringXY(1,0, buff);
}   

void View::deleteMember()
{
    char buff[30];
    sprintf(buff,"delete member?        ");
    lcd -> WriteStringXY(0,0, buff);
    sprintf(buff,"                      ");
    lcd -> WriteStringXY(1,0, buff);
}
void View::DeleteMember()
{
    char buff[30];
    sprintf(buff,"delete member !!     ");
    lcd -> WriteStringXY(0,0, buff);
    sprintf(buff,"                      ");
    lcd -> WriteStringXY(1,0, buff);
}
   