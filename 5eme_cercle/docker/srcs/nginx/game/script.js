const gameTime = 30;
const flySpawn = 2;
const flySpeed = 12;
const tps = 35;
const flysPop = 8;
const flySize = 70;

var highscore = getCookie('highscore') || 0;
var score = 0;
var time = 0;
var flyNbr = 0;

var htmlCach = document.getElementById("cach");
var htmlCase = document.getElementById("case");
var htmlScore = document.getElementById("score");
var htmlTime = document.getElementById("time");
var htmlHighscore = document.getElementById("highscore");
var body = document.getElementById("bodbod");
var patpat = document.getElementById("pat");
var htmlFlys = document.getElementById("flys");
var hearts = document.getElementById("hearts");

htmlHighscore.innerHTML = `Best Score<br/>${highscore}`;

var flys = [];

function getRandomInt(max) {
  return Math.floor(Math.random() * max);
}

function addFly()
{
	var link = document.createElement("a");
	link.href = "javascript:pat();"

	var object = document.createElement("img");
	object.classList.add("fly");
	object.id = `fly${flyNbr}`
	object.src = "fly.png";
	object.style.transform = `rotate(${Math.floor(Math.random()*360)}deg)`

	var speed = Math.floor(flySpeed + (flySpeed/5*Math.random()-flySpeed/10))

	var y = getRandomInt(2)*(window.innerHeight+600)-300;
	var x = getRandomInt(window.innerWidth);

	//var vx = 0.5 * ((x-window.innerWidth/2)/(window.innerWidth/2))
	
	if(x > window.innerWidth/2) { var vx = -0.8+Math.random()/2 }
	else { var vx = 0.8+Math.random()/2 }

	if(y > 0) { var vy = -0.8+Math.random()/2 }
	else { var vy = 0.8+Math.random()/2 }

	flys.push({x:x, y:y, vx:vx, vy:vy, speed:speed, nbr:flyNbr})
	
	link.appendChild(object);
	document.getElementById("flys").appendChild(object);
	flyNbr += 1;
}

function start()
{
	htmlCach.style.opacity = "0%";
	htmlCase.style.display = "none";
	body.style.cursor = "none";
	htmlScore.innerHTML = "PatPat : 0";
	htmlFlys.innerHTML = "";
	flys = [];

	time = gameTime;
	flyNbr = 0;

	for(i=0;i<flysPop;i++) { addFly(); }

	timeIncr();
	tick();
}

function gameover()
{
	htmlCach.style.opacity = "70%";
	htmlCase.style.display = "block";
	body.style.cursor = "auto";

	if(score > highscore)
	{
		highscore = score;

		setCookie('highscore',highscore,99999);
	}

	score = 0;
	htmlHighscore.innerHTML = `Best Score<br/>${highscore}`
}

function pat()
{
	score += 1;
	htmlScore.innerHTML = `PatPat : ${score}`;
}

function tick(){
	if(time <= 0) { return; }

	var tempFlys = [];

	for(i=0;i<flys.length;i++) {
		flys[i].x += flys[i].vx * flys[i].speed;
		flys[i].y += flys[i].vy * flys[i].speed;

		document.getElementById(`fly${flys[i].nbr}`).style.left = flys[i].x - 35;
		document.getElementById(`fly${flys[i].nbr}`).style.top = flys[i].y - 35;

		if( (flys[i].vx > 0 && flys[i].x > window.innerWidth+100) ||
			(flys[i].vx < 0 && flys[i].x < -100) ||
			(flys[i].vy > 0 && flys[i].y > window.innerHeight+100) ||
			(flys[i].vy < 0 && flys[i].y < -100) ) {
			document.getElementById(`fly${flys[i].nbr}`).remove();
			addFly();
		} else {
			tempFlys.push(flys[i])
		}
	}

	flys = tempFlys;

	setTimeout(tick, Math.floor(1000/tps));
}

async function timeIncr(){
	if(time > 0) { time += -1; htmlTime.innerHTML = `${time}`; }
	else { gameover(); return; }

	setTimeout(timeIncr, 1000);
}

window.addEventListener("click", function(event) {
	if(time > 0) {
		for(i=0;i<flys.length;i++) {
			
			if(Math.abs(flys[i].x - event.clientX) < flySize && Math.abs(flys[i].y - event.clientY) < flySize) {
				flys[i].speed += 2
				pat();

				var prtc = document.createElement("img");
				prtc.src = "heart.png";
				prtc.classList.add("heart");
				prtc.style.left = flys[i].x; prtc.style.top = flys[i].y;
				hearts.appendChild(prtc);
				setTimeout(function() { prtc.remove(); }, 1000);

				return;
			}
		}
	}
});

window.onmousemove = function(event){
	patpat.style.left = `${event.clientX - 25}px`;
	patpat.style.top = `${event.clientY - 25}px`;
}

window.ondragstart = function() { return false; } 

// Cookies

function setCookie(name,value,days) {
    var expires = "";
    if (days) {
        var date = new Date();
        date.setTime(date.getTime() + (days*24*60*60*1000));
        expires = "; expires=" + date.toUTCString();
    }
    document.cookie = name + "=" + (value || "")  + expires + "; path=/";
}

function getCookie(name) {
    var nameEQ = name + "=";
    var ca = document.cookie.split(';');
    for(var i=0;i < ca.length;i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1,c.length);
        if (c.indexOf(nameEQ) == 0) return c.substring(nameEQ.length,c.length);
    }
    return null;
}