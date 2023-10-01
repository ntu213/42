let i = 4;
const main = function main(){
	const fs = require('fs')
	if (i <= 0)
		return
	if (fs.existsSync('Sully_5.js'))
		i--;
	fs.writeFile('Sully_' + i + '.js', 'let i = ' + i + ';\nconst main = ' + main.toString() + '\nmain();\nmodule.exports.main = main;\n', (function err(error){
		if (!error)
		{
			try {
			const next = require('./Sully_' + i + '.js');
			next.main();
			} catch {}
		}
	}));
}
main();
module.exports.main = main;
