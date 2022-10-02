import { Status } from "../../src/types/Status";


export const ChainManagerMock = ()=>{
    jest.mock('../../src/controllers/chainbuilder/ChainManager', () => {
        return{
            ChainManager: jest.fn().mockImplementation(()=>{
                return {
                  addService: ()=>{return { status: Status.SUCCESS, message: null }},
                  removeService: ()=>{return { status: Status.SUCCESS, message: null }},
                  handleChainBuilderRequest: ()=>{}                  
                }
            })
        }
    });
}