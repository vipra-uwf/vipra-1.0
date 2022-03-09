
const bcrypt = require('bcrypt')

const SaltRounds = 2 ** 10;

class PasswordManager_bcrypt{
    constructor(){}

    async HashPassword(password){
        return bcrypt.hash(password, SaltRounds);
    }

    async CheckPassword(password, dbpassword){
        return bcrypt.compare(password, dbpassword);
    }
}

module.exports = PasswordManager_bcrypt;