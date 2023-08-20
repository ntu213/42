let pmp = prompt("Tape ton mot: ")
let test = document.getElementById("test")
let body = document.querySelector("body")
if (pmp == "toto")
	console.log("wah tu sais ecrire")
else
	console.log("gros naze")
console.log(test)
setTimeout(function() {
	test.textContent = "second test"
	console.log(test)
}, 2000)
console.log(body)
