
class UserRepo_Mongo{

    #dbModel;

    constructor(DBCon){
        if(DBCon === null){
            throw `User Database Connection is null`;
        }
        this.#dbModel = DBCon;
    }

    async FindByEmail(uemail){
        return await this.#dbModel.findOne({email: uemail});
    }

    // TODO make sure users can't delete arbitrary users -RG
    // TODO check that the user calling the delete is the user to be deleted or has permissions -RG
    async DeleteUser(uemail){
        const deleted = await this.#dbModel.deleteOne({email: uemail});
        return deleted.deletedCount === 1;
    }

    async RegisterUser(uemail, hashedPass){
        const exists = await this.#dbModel.exists({email: uemail}).exec();
        if(exists){
            return null;
        }else{
            return await this.#dbModel.create({
                email: uemail,
                password: hashedPass
            });
        }
    }
}

module.exports = UserRepo_Mongo;