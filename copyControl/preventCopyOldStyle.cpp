/*
 * =====================================================================================
 *
 *       Filename:  preventCopyOldStyle.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  Sunday 16 July 2017 07:07:14  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <iostream>

class NoCopyOldStyle
{
    public:
       NoCopyOldStyle()= default;
       ~NoCopyOldStyle()= default;

    void useCopyConstructor()
    {
        NoCopyOldStyle obj;
        NoCopyOldStyle obj1  = obj;
    }

    private:
       NoCopyOldStyle(const NoCopyOldStyle& noCopyObj);
       NoCopyOldStyle& operator=(const NoCopyOldStyle& noCopyObj);
};


int main()
{
    NoCopyOldStyle obj;
    NoCopyOldStyle obj1 = obj;
    //obj.useCopyConstructor();  --> This results in linking errors

}
