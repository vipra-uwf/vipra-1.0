const fs        = require('fs');
const fsExtra   = require('fs-extra');

const CopyFileTo = async (fromPath, toPath)=>{
    if(fs.existsSync(fromPath)){
        await fsExtra.copyFile(fromPath, toPath);
        return true;
    }
    console.log(`[ERROR] Attempt to copy a file that does not exist: ${fromPath}`);
    return false;
}

const MakeDir = async (dirPath)=>{
    if(fs.existsSync(dirPath)){
        return false;
    }
    fs.mkdirSync(dirPath);
    return true;
}

const WriteNewFile = async (fileContent, filePath)=>{
    if(fs.existsSync(filePath)){
        return false;
    }else{
        fs.writeFileSync(filePath, fileContent, {flag:'a'});
        return true;
    }    
}

const DeleteFile = async (filePath)=>{
    if(fs.existsSync(filePath)){
        fs.rmSync(filePath);
        return true;
    }
    console.log(`[ERROR] Attempt to delete file that does not exist: ${filePath}`);
    return false;
}

const DeleteDirectory = async (dirPath)=>{
    if(fs.existsSync(dirPath)){
        fs.rmSync(dirPath, { recursive: true, force: true });
        return true;
    }
    console.log(`[ERROR] Attempt to delete directory that does not exit: ${dirPath}`);
    return false;
}

const CopyDirContentsTo = async (fromDir, toDir)=>{
    if(fs.existsSync(fromDir)){
        if(fs.existsSync(toDir)){
            await fsExtra.copy(fromDir, toDir);
            return true;
        }
        console.log(`[ERROR] Attempt to copy TO directory that does not exist: ${toDir}`);
        return false;
    }
    console.log(`[ERROR] Attempt to copy FROM directory that does not exist: ${fromDir}`);
    return false;
}

const DoesFileExist = async (filePath)=>{
    return fs.existsSync(filePath);
}

// TODO directory compress method -RG


module.exports = {
    CopyFileTo,
    DeleteFile,
    CopyDirContentsTo,
    DeleteDirectory,
    MakeDir,
    DoesFileExist,
    WriteNewFile
}


