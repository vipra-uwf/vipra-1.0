
const { EXISTANT_FILE, NON_EXISTANT_FILE, TEST_DIR, NON_EXISTANT_DIR, TEST_TEXT_FILE, TESTFILE_DIR, MAKEDIR_PATH, COPYTEST_DIR } = require('../TEST_FILES/FILE_PATHS');

const {
    CopyFileTo,
    DeleteFile,
    CopyDirContentsTo,
    DeleteDirectory,
    MakeDir,
    DoesFileExist,
    WriteNewFile
} = require('../../controllers/Files/FileOperations');


beforeEach(()=>{
});

test('WriteNewFile', async ()=>{
    const testText = "this is test text";
    let result = await WriteNewFile(testText, TEST_TEXT_FILE);
    let exists = await DoesFileExist(TEST_TEXT_FILE);
    expect(result).toBe(true);
    expect(exists).toBe(true);
    expect(await DeleteFile(TEST_TEXT_FILE)).toBe(true);
});

test('CopyFileTo', async ()=>{

    const toPath = COPYTEST_DIR.concat('/COPY_TEST');
    
    // Copy file correctly -RG --------------------------------------------
    let result = await CopyFileTo(EXISTANT_FILE, toPath);
    let exists = await DoesFileExist(toPath);
    expect(result).toBe(true);
    expect(exists).toBe(true);
    expect(await DoesFileExist(EXISTANT_FILE)).toBe(true);
    expect(await DeleteFile(toPath)).toBe(true);
    
    // Copy non-existant file -RG -----------------------------------------
    result = await CopyFileTo(NON_EXISTANT_FILE, toPath);
    exists = await DoesFileExist(toPath);
    expect(result).toBe(false);
    expect(exists).toBe(false);
});

test('MakeDir', async ()=>{
    // Attempt to make directory -RG -------------------------------------
    let result = await MakeDir(MAKEDIR_PATH);
    let exists = await DoesFileExist(MAKEDIR_PATH);
    expect(result).toBe(true);
    expect(exists).toBe(true);
    expect(await DeleteDirectory(MAKEDIR_PATH)).toBe(true);

    // Attempt to make directory that exists -RG ----------------------------
    result = await MakeDir(TEST_DIR);
    expect(result).toBe(false);
});

test('DeleteDirectory', async ()=>{
    let result = await DeleteDirectory(NON_EXISTANT_DIR);
    expect(result).toBe(false);
});

test('CopyDirContentsTo', async ()=>{
    let result = await CopyDirContentsTo(TEST_DIR, COPYTEST_DIR);
    let exists = await DoesFileExist(COPYTEST_DIR.concat('/FILE_IN_DIR'));
    expect(result).toBe(true);
    expect(exists).toBe(true);
    expect(await DeleteFile(COPYTEST_DIR.concat('/FILE_IN_DIR'))).toBe(true);

    // Attempt to copy from non existant dir
    result = await CopyDirContentsTo(NON_EXISTANT_DIR, COPYTEST_DIR);
    expect(result).toBe(false);
});

test('DoesFileExist', async ()=>{

    // Check for existant file -RG ----------------------------------------
    let result = await DoesFileExist(EXISTANT_FILE);
    expect(result).toBe(true);

    // Check for non existant file -RG ----------------------------------------
    result = await DoesFileExist(NON_EXISTANT_FILE);
    expect(result).toBe(false);
});

