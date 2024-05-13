#ifndef VALIDADOREMAIL_HPP
#define VALIDADOREMAIL_HPP


#include <string>
class ValidadorEmail{
    //Atributos prtoegidos accedibles en esta clase y clasesheredadas
    protected:
        std::string email;

 
    public:
        ValidadorEmail(std::string _email);
        void validarCorreo();

};

#endif //VALIDADOREMAIL_HPP