const config = require('../../configurations/config');
const { DoesFileExist, DeleteDirectory } = require('../../controllers/Files/FileOperations');

const { TEST_BUILD_PATH, TEST_SRC_PATH } = require('../TEST_FILES/FILE_PATHS');

const Good_ImageBuilder = new config.image.ImageBuilder({
                                            buildPath: TEST_BUILD_PATH,
                                            srcPath: TEST_SRC_PATH,
                                            includePath: TEST_SRC_PATH
                                        });

const Bad_ImageBuilder = new config.image.ImageBuilder({
                                            buildPath: "notadir",
                                            srcPath: "notadir",
                                            includePath: "notadir"
                                        });                                        

test('BuildCompilationTar', async ()=>{
    let result = await Good_ImageBuilder.BuildCompilationTar(null, "test");
    let exists = await DoesFileExist(result);
    expect(result).toBe(TEST_BUILD_PATH.concat('/test.tar'));
    expect(exists).toBe(true);

    result = await Good_ImageBuilder.CleanUpBuild('test');
    expect(result).toBe(true);

    // Attempt to build from bad paths
    result = await Bad_ImageBuilder.BuildCompilationTar(null, "test");
    exists = await DoesFileExist(result);
    expect(result).toBeNull();
    expect(exists).toBe(false);
});

test('MakeBuildDir', async ()=>{
    let result = await Good_ImageBuilder.MakeBuildDir("testDir");
    let exists = await DoesFileExist(result);

    expect(result).not.toBeNull();
    expect(exists).toBe(true);

    result = await DeleteDirectory(result);
    expect(result).toBe(true);
});

test('CleanUpBuild', async ()=>{
    let result = await Good_ImageBuilder.BuildCompilationTar(null, "test");
    let exists = await DoesFileExist(result);
    expect(result).toBe(TEST_BUILD_PATH.concat('/test.tar'));
    expect(exists).toBe(true);
    let tarPath = result

    result = await Good_ImageBuilder.CleanUpBuild('test');
    exists = await DoesFileExist(tarPath);
    expect(result).toBe(true);
    expect(exists).toBe(false);
    

    // Attempt to clean up build that doesn't exist -RG
    result = await Good_ImageBuilder.CleanUpBuild('notabuild');
    expect(result).toBe(false);
});