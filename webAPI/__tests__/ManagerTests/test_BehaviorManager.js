const config = require('../../configurations/config');
const { Status } = require('../../configurations/Status');
const { TESTFILE_DIR } = require('../TEST_FILES/FILE_PATHS');

const { DoesFileExist, DeleteFile } = require('../../controllers/Files/FileOperations');


const BehaviorRepo      = new config.repos.mocks.mock_BehaviorRepo();
const BehaviorManager   = new config.behavior.BehaviorManager(BehaviorRepo);

const TEST_AUTH = {
    email: "testing@email.com"
};

beforeEach(()=>{
    BehaviorRepo.Reset(true);
});

test('Has Interface Functions', async ()=>{
    expect(BehaviorManager.CreateBehavior).toEqual(expect.anything());
    expect(BehaviorManager.UpdateBehavior).toEqual(expect.anything());
    expect(BehaviorManager.StageBehavior).toEqual(expect.anything());
    expect(BehaviorManager.UnStageBehavior).toEqual(expect.anything());
    expect(BehaviorManager.DeleteBehavior).toEqual(expect.anything());
    expect(BehaviorManager.GetBehaviorOptions).toEqual(expect.anything());
});

test('Creating Behavior', async ()=>{

    let createCallCount = 0;

    // Attempt to create behavior that is properly formatted
    const testBehavior = {
        name: "testBehavior",
        content: "this is a test behavior",
        publish: true
    };
    let result = await BehaviorManager.CreateBehavior(testBehavior, TEST_AUTH);
    createCallCount++;
    expect(result).toBe(Status.CREATED);

    // Attempt to create behavior that should not be accepted -RG
    const badBehavior = {
        name: "badBehavior",
        publish: true
    };
    result = await BehaviorManager.CreateBehavior(badBehavior, TEST_AUTH);
    expect(result).toBe(Status.BAD_REQUEST);


    // Attempt to create a behavior while not authorized -RG
    const bad_auth = null;
    result = await BehaviorManager.CreateBehavior(testBehavior, bad_auth);
    expect(result).toBe(Status.UNAUTHORIZED);

    expect(BehaviorRepo.CallCounts()["Create"]).toBe(createCallCount);
});

test('Updating Behavior', async ()=>{

    let updateCalls = 0;

    // Attempt to update existing behavior -RG -----------------------------------------------------------
    const goodBehavior = {
        name: "exampleBehavior",
        content: "this behavior has been updated"
    }
    let result = await BehaviorManager.UpdateBehavior(goodBehavior, TEST_AUTH);
    expect(result).toBe(Status.SUCCESS);
    updateCalls++;

    // Attempt to update non-existant behavior -RG -----------------------------------------------------------
    const nonExistantBehavior = {
        name: "doesntExist",
        content: "doesn't matter"
    }
    result = await BehaviorManager.UpdateBehavior(nonExistantBehavior, TEST_AUTH);
    expect(result).toBe(Status.NOT_FOUND);

    // Attempt to update behavior "I" didn't create -RG -----------------------------------------------------------
    result = await BehaviorManager.UpdateBehavior(goodBehavior, {email: "didntmakeanything@email.com"});
    expect(result).toBe(Status.FORBIDDEN);

    // Attempt to update without update params -RG -----------------------------------------------------------
    const noContentBehavior = {
        name: "exampleBehavior"
    }
    result = await BehaviorManager.UpdateBehavior(noContentBehavior, TEST_AUTH);
    expect(result).toBe(Status.BAD_REQUEST);

    // Attempt to update while not authorized -RG -----------------------------------------------------------
    result = await BehaviorManager.UpdateBehavior(goodBehavior, null);
    expect(result).toBe(Status.UNAUTHORIZED);

    expect(BehaviorRepo.CallCounts()["Update"]).toBe(updateCalls);
});

test('Staging Behavior', async ()=>{
    
    let getBehaviorCalls = 0;

    // Attempt to stage existing behavior -RG -----------------------------------------------------------
    const TestFilePath = TESTFILE_DIR.concat('/exampleBehavior.behavior');
    let result = await BehaviorManager.StageBehavior('exampleBehavior', TESTFILE_DIR);
    let exists = await DoesFileExist(TestFilePath);
    getBehaviorCalls++;
    expect(result).toBe(Status.SUCCESS);
    expect(exists).toBe(true);
    expect(await DeleteFile(TestFilePath)).toBe(true);

    // Attempt to stage nonexistant behavior -RG -----------------------------------------------------------
    result = await BehaviorManager.StageBehavior('doesntexist', TestFilePath);
    exists = await DoesFileExist(TestFilePath);
    getBehaviorCalls++;
    expect(result).toBe(Status.NOT_FOUND);
    expect(exists).toBe(false);

    // Attempt to stage nonpublished behavior -RG -----------------------------------------------------------
    result = await BehaviorManager.StageBehavior('unpublished', TestFilePath);
    exists = await DoesFileExist(TestFilePath);
    getBehaviorCalls++;
    expect(result).toBe(Status.FORBIDDEN);
    expect(exists).toBe(false);

    expect(BehaviorRepo.CallCounts()['GetBehavior']).toBe(getBehaviorCalls);
});

/*  Not Sure if needed atm -RG

test('Unstaging Behavior', async ()=>{
    
    let result = await BehaviorManager.StageBehavior("exampleBehavior", TESTFILE_DIR);
    expect(result).toBe(Status.SUCCESS);
    
    // Unstage staged behavior
    result = await BehaviorManager.UnStageBehavior("exampleBehavior", TESTFILE_DIR);
    expect(result).toBe(Status.SUCCESS);

    // Unstage non-staged behavior
    result = await BehaviorManager.UnStageBehavior("examplebehavior", TESTFILE_DIR);
    expect(result).toBe(Status.NOT_FOUND);

    // Unstage non existant behavior
    result = await BehaviorManager.UnStageBehavior("notabehavior", TESTFILE_DIR);
    expect(result).toBe(Status.NOT_FOUND);
});
*/

test('Deleting Behavior', async ()=>{
    let deleteCalls = 0;

    // Attempt to delete behavior
    let result = await BehaviorManager.DeleteBehavior("exampleBehavior", TEST_AUTH);
    deleteCalls++;
    expect(result).toBe(Status.SUCCESS);

    // Attempt to delete non existant behavior
    result = await BehaviorManager.DeleteBehavior("notabehavior", TEST_AUTH);
    expect(result).toBe(Status.NOT_FOUND);

    // Attempt to delete someone else's behavior
    result = await BehaviorManager.DeleteBehavior("secondBehavior", TEST_AUTH);
    expect(result).toBe(Status.FORBIDDEN);

    expect(BehaviorRepo.CallCounts()['Delete']).toBe(deleteCalls);
});

test('Getting Behavior Options', async ()=>{

    const published = [
        {name: "exampleBehavior", creator: "testing@email.com", publish: true},
        {name: "secondBehavior", creator: "other@email.com", publish: true}
    ];

    const all = [
        {name: "exampleBehavior", creator: "testing@email.com", publish: true},
        {name: "secondBehavior", creator: "other@email.com", publish: true},
        {name: "unpublished", creator: "test@email.com", publish: false}
    ]

    // Get options, only published should show
    let result = await BehaviorManager.GetBehaviorOptions(TEST_AUTH);
    expect(result).toEqual(published);

    // Get Options, all should show
    result = await BehaviorManager.GetBehaviorOptions({email: "test@email.com"});
    expect(result).toEqual(all);

});