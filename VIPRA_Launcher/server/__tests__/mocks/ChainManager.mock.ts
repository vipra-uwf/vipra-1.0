

export const ChainManagerMock = ()=>{
    jest.mock('../../src/controllers/chainbuilder/ChainManager', () => {
        return{
            ChainManager: jest.fn().mockImplementation(()=>{
                return {
                  addNewService: ()=>{},
                  removeService: ()=>{},
                  handleChainBuilderRequest: ()=>{}                  
                }
            })
        }
    });
}