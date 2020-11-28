#include "util.h"

Util::Util(QObject *parent) : QObject(parent){

}

/*!
	Hashes a password using a hashfunction
	/return Hashed password as int
*/
int Util::hashPassword(QString password){
    std::string s = password.toLocal8Bit().constData();
    const size_t InitialFNV = 2166136261U;
    const size_t FNVMultiple = 16777619;
    size_t hash = InitialFNV;
    for(size_t i = 0; i < s.length(); i++)
    {
        hash = hash ^ (s[i]);       /* xor  the low 8 bits */
        hash = hash * FNVMultiple;  /* multiply by the magic number */
    }
    return hash;
}

/*!
	Checks if a password is valid, of size at least 4 and have special chars
	/return True if valid, false otherwise.
*/
bool Util::checkPassword(QString password){
     std::string pw = password.toLocal8Bit().constData();
     bool special = false,
     cap = false,
     len = false,
     digit = false,
     lower=false;

     // Check length
     if (pw.length() > 4)
         len = true;
     else // No need to check anything else if they miss this
         return false;

     // Loop through the password, setting values to true
     // when encountering them
     for (const auto &ch : pw)
     {
         if (ispunct(ch))
             special = true;
         if (isdigit(ch))
             digit = true;
         if (isupper(ch))
             cap = true;
         if (islower(ch))
             lower = true;
     }
     return special && cap && len && digit && lower;
}




