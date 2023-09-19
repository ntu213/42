async function nutnut() {

	
	const CLIENT_ID = 'u-s4t2ud-2277ee8fb062a2a22e6321cda45ea52ff6df05c1182b7e050110174bb06aa24a';
const CLIENT_SECRET = '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';
const REDIRECT_URI = 'http://localhost:3001/login';
const AUTH_URL = 'https://api.intra.42.fr/oauth/authorize';
const TOKEN_URL = 'https://api.intra.42.fr/oauth/token';

const formData = new URLSearchParams();
formData.append('client_id', CLIENT_ID);
formData.append('client_secret', CLIENT_SECRET);
formData.append('code', 'ad64ab5cdbf39a7a81c15ab38993952e378a5bfecb5149be92c55b9984f27bf6');
formData.append('redirect_uri', REDIRECT_URI);
formData.append('grant_type', 'authorization_code');

const response = await fetch(TOKEN_URL, {
    method: 'POST',
	mode: 'no-cors',
    headers: {
    'Content-Type': 'application/x-www-form-urlencoded',
},
    body: formData,
});

if (!response.ok) { return { }; }
const tokenData = await response.json();

const token = tokenData["access_token"]
console.log(token)
}
// fetch('https://api.intra.42.fr/v2/me')
// 	.then(response => response.json())
// 	.then(data => {
// 		// Traitez les données de l'API ici
// 		console.log(data);
// 	})
// 	.catch(error => {
// 		console.error('Erreur lors de la récupération des données de l\'API', error);
// 	});

nutnut()