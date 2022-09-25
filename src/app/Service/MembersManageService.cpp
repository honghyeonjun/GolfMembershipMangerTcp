#include "MembersManageService.h"
#include <cstring>

MembersManageService::MembersManageService(ComDev *comDev,View *view)
{
    membersEntity = new MembersEntity();
    membersManagerState = FOUND_MEMBER;
    this ->view = view;
    this->comDev = comDev;

}

MembersManageService::~MembersManageService()
{
}

void MembersManageService::setComDev(ComDev *comDev)
{
    this->comDev = comDev;
}

void MembersManageService::updateStateEvent(std::string devName)
{
    switch (membersManagerState)
    {
        case CARD_READER :
            if (devName == "ModeButton") {
                membersManagerState = CARD_REGISTER;
                printf("changed to CARD_REGISTER State\n");
                view -> GolfMembersInfo(membersManagerState);
            }
        break;
        case CARD_REGISTER :
            if (devName == "ModeButton") {
                membersManagerState = FOUND_MEMBER;
                view -> GolfMembersInfo(membersManagerState);
                printf("changed to FOUND_MEMBER State\n");
                findMember();
            } //추가한부분
        break;
        case FOUND_MEMBER :
            if(devName == "ModeButton") 
            {
                membersManagerState = CARD_READER;
                printf("changed to CARD_READER State\n");
                view -> GolfMembersInfo(membersManagerState);
            }
        break;
    }
}

void MembersManageService::checkCardNumber(int *cardNum)
{
    switch (membersManagerState)
    {
        static int id = 100000;
        char name[20];
        char address[40];
        char phoneNumber[15];

        case CARD_READER :
            if (membersEntity->findMemberInfo(cardNum)) {
                printf("Registered Member!\n");
                view ->RegisteredMember();
                membersEntity->printMemberInfo(cardNum);
                comDev->sendData(cardNum);
            }
            else {
                printf("Not Registered Member!\n");
                view -> notRegisteredMember();
            }
        break;
        case CARD_REGISTER :
            MemberInfo tempMember;
            tempMember.id = id;
            id++;
            view -> MemberRegisterMode();
            std::cout<<"name:";
            std::cin>> name;
            std::cout << "address : ";
            std::cin>>address;
            std::cout << "phoneNumber : ";
            std::cin >> phoneNumber;

            strcpy(tempMember.name, name);
            strcpy(tempMember.address, address);
            strcpy(tempMember.phoneNumber, phoneNumber);
            memcpy(tempMember.cardNum, cardNum, sizeof(tempMember.cardNum));
            
            membersEntity->addMemberInfo(tempMember);
            printf("Member Registered!\n");
            view ->RegisteredMemberInfo(name);
        break;


    }
}

void MembersManageService::findMember()
{
        char MembersInfo[40];
        
        std::cout<<"name , address , phoneNumber(choose one):";
        std::cin>> MembersInfo;

        if (membersEntity->findMemberInfo(MembersInfo)) 
        {
            printf("found Member!\n");
            membersEntity->printMemberInfo(MembersInfo);
            view -> MemberFound(MembersInfo);
        }
        else 
        {
            printf("Not found Member!\n");
            view -> MemberNotFound();
        }

}
