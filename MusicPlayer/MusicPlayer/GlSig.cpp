#include "GlSig.h"

GlobalSig* GlobalSig::GetInstance()
{
    static GlobalSig _instance;
 
    return &_instance;
}
