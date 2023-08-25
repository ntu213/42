//let pmp = prompt("Tape ton mot: ")
let test = document.getElementById("test")
let body = document.querySelector("body")
//if (pmp == "toto")
	console.log("wah tu sais ecrire")
//else
	console.log("gros naze")
console.log(test)
setTimeout(function() {
	test.textContent = "second test"
	console.log(test)
}, 2000)
console.log(body)

button = document.getElementById("button1")
button.addEventListener("click", function() {
	let cache = button.textContent
	button.textContent = "Hey! I'm a button clicked less than 1 sec ago!"
	setTimeout(function(){
		button.textContent = cache
	}, 1000)
})

document.addEventListener("mousemove", function(event) {
	coords = this.getElementById("coord")
	coords.textContent = "X = " + event.clientX + "\nY = " + event.clientY
})