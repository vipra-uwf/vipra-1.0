const exec = require("child_process").exec;

let vipraProcess = exec('./run.sh');
vipraProcess.stdout.on('data', function(data) {
	console.log(data);
});

const home = async function (req, res) {
    res.send("Hello!");
  }
  
  module.exports = {
    home
  };