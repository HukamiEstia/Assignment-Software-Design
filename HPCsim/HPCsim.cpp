// HPCsim.cpp : Définit les fonctions exportées de la DLL.
//

#include "pch.h"
#include "framework.h"
#include "HPCsim.h"


// Il s'agit d'un exemple de variable exportée
HPCSIM_API int nHPCsim=0;

// Il s'agit d'un exemple de fonction exportée.
HPCSIM_API int fnHPCsim(void)
{
    return 0;
}

// Il s'agit du constructeur d'une classe qui a été exportée.
CHPCsim::CHPCsim()
{
    return;
}
