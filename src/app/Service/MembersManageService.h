#ifndef __MEMBERSMANAGESERVICE_H__
#define __MEMBERSMANAGESERVICE_H__
#include <string>
#include "MembersEntity.h"
#include "MemberInfo.h"
#include "ComDev.h"
#include "MembersManageService.h"
#include "View.h"


//enum {CARD_READER, CARD_REGISTER, FOUND_MEMBER};

class MembersManageService
{
private:
    int membersManagerState;
    int findmembersState;
    View *view;
    MembersEntity *membersEntity;
    ComDev  *comDev;

public:
    MembersManageService(ComDev *comDev,View *view);
    virtual ~MembersManageService();
    void setComDev(ComDev *comDev);
    void updateStateEvent(std::string devName);
    void checkCardNumber(int *cardNum);
    void findMember();
   

};

#endif /* __MEMBERSMANAGESERVICE_H__ */