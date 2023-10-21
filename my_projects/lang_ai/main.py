
import os
import re

MIN_LETTERS = 3
LEARNING = True

def load_language(lang:str):
	file = open("lang/" + lang.lower() + ".lang", "a+")
	file.close()
	file = open("lang/" + lang.lower() + ".lang", "r+")
	res = ()
	lines = file.readlines()
	for s in lines:
		if len(s[0:-1]) > 0:
			res += (s[0:-1],)
	# print(lines)
	# print(res)
	file.close()
	return (res)

def load_all_lang():
	file = open("lang/languages.count", "r+")
	langs = file.readlines()
	res = {}
	for l in langs:
		if (l[0:-1] != ""):
			res[l[0:-1]] = load_language(l[0:-1])
	file.close()
	return (res)

def add_to_lang(lang:str, words:list[str]):
	if (os.path.exists("lang/" + lang.lower() + ".lang") == False):
		add_lang(lang)
	file = open("lang/" + lang.lower() + ".lang", "a+")
	tab = load_language(lang)
	for elem in words:
		if (elem != "" and elem.lower() not in tab and len(elem) > MIN_LETTERS):
			file.write(elem.lower() + "\n")
			tab += (elem.lower(),)
	file.close()

def add_lang(lang:str):
	all = load_all_lang()
	if (lang in all):
		return

	file = open("lang/" + lang.lower() + ".lang", "a+")
	file.close()
	file = open("lang/languages.count", "a")
	file.write(lang.lower() + "\n")
	file.close()






def delete_accent(s:str):
	map = {
		'à': 'a', 'â': 'a', 'ä': 'a',
		'é': 'e', 'è': 'e', 'ê': 'e', 'ë': 'e',
		'î': 'i', 'ï': 'i',
		'ô': 'o', 'ö': 'o',
		'ù': 'u', 'û': 'u', 'ü': 'u',
		'ç': 'c'
	}
	res = ""
	for i in range(len(s)):
		if (s[i] in map):
			res += map[s[i]]
		else:
			res += str(s[i])
	return (res)

def countSameCharacters(w1:str, w2:str):
	n = 0
	for i in range(min(len(w1), len(w2))):
		if	w1[i] == w2[i]:
			n += 1
	return (n)

def checkWithPercentage(w1:str, w2:str):
	w1 = delete_accent(w1)
	w2 = delete_accent(w2)
	if abs(len(w1) - len(w2)) > 1:
		return False
	if w1 == 'oral' and w2 == 'orel':
		print(int(min(len(w1), len(w2)) * 0.9))
	if countSameCharacters(w1, w2) < int(min(len(w1), len(w2)) * 0.7):
		return False
	# print(w1, ":", w2)
	return True

def is_word_in_lang(word:str, lang:list[str]):
	for el in lang:
		# if el == word:
		if checkWithPercentage(el, word):
			return True
	return False

def getMaxIndex(tab:dict[str:int]):
	res = ""
	n = -1
	for el in tab:
		print(tab[el])
		if tab[el] > n:
			n = tab[el]
			res = el
	return res

def find_language(sent:str):
	# sent = delete_accent(sent)
	al = re.findall(r'\b[a-zA-Zàâäéèêëîïôöùûüç]+\b', sent)
	for el in al:
		if len(el) < MIN_LETTERS:
			al.remove(el)
	# print("all=", al)
	langs = load_all_lang()
	res = {}
	for lang in langs:
		res[lang] = 0
		for word in al:
			if (is_word_in_lang(word, langs[lang])):
				res[lang] += 1
	final = getMaxIndex(res)
	if LEARNING:
		add_to_lang(final, al)
	return final


def find_language_int(sentence:str):
	s = find_language(sentence)
	if (s == "french"):
		return (0)
	if (s == "english"):
		return (1)
	return (2)

def printer():
	everything = load_all_lang()
	for elem in everything:
		print(elem, everything[elem])

# printer()
print(find_language(""))


# print(find_language("Comment puis-je mettre à jour mes informations de facturation pour mon abonnement ?Pouvez-vous m'expliquer en détail les fonctionnalités incluses dans mon abonnement ?Y a-t-il des frais supplémentaires associés à mon abonnement actuel que je devrais connaître ?Pouvez-vous m'indiquer la date de renouvellement de mon abonnement et le montant prélevé ?Comment puis-je résilier mon abonnement et quelles sont les conditions de résiliation ?Existe-t-il des options de mise à niveau vers un abonnement supérieur avec plus de fonctionnalités ?Puis-je suspendre temporairement mon abonnement sans perdre mes avantages actuels ?Comment accéder à mon historique de paiement et à mes factures précédentes ?Y a-t-il des offres promotionnelles ou des réductions disponibles pour les abonnés actuels ?Pouvez-vous m'expliquer la politique de remboursement en cas de résiliation anticipée de mon abonnement ?Comment puis-je modifier les préférences de notification liées à mon abonnement ?Pouvez-vous m'aider à résoudre un problème de paiement ou de renouvellement de mon abonnement ?Quelle est la durée de validité de mon abonnement, et comment puis-je le prolonger ?Pouvez-vous me fournir un récapitulatif des services inclus dans mon abonnement mensuel/annuel ?Existe-t-il des tarifs spéciaux pour les étudiants ou les organisations à but non lucratif ?Comment puis-je mettre en pause mon abonnement pendant une période de vacances ou d'inactivité ?Y a-t-il des restrictions géographiques ou d'accès à certains contenus en fonction de mon abonnement ?Puis-je transférer mon abonnement à un autre utilisateur ou à un membre de ma famille ?Comment puis-je obtenir de l'assistance technique ou un support dédié en tant qu'abonné ?Pouvez-vous me rappeler les avantages spécifiques liés à mon niveau d'abonnement par rapport aux niveaux inférieurs ?Pouvez-vous m'indiquer comment renouveler mon abonnement actuel ?Quels sont les avantages inclus dans mon plan d'abonnement actuel ?Existe-t-il des options de facturation annuelle pour économiser sur mon abonnement ?Quelle est la politique de remboursement en cas d'annulation de mon abonnement ?Comment puis-je mettre à jour les informations de ma carte de crédit pour les paiements récurrents ?Pouvez-vous m'expliquer les différences entre les niveaux d'abonnement que vous proposez ?Y a-t-il des coûts cachés associés à mon abonnement actuel que je devrais connaître ?Comment puis-je ajouter des utilisateurs supplémentaires à mon abonnement ?Quelle est la fréquence de facturation pour mon abonnement : mensuelle, annuelle, ou autre ?Puis-je suspendre temporairement mon abonnement sans résilier définitivement ?Quelle est la politique de rétention des données pour les comptes résiliés ?Comment puis-je télécharger des factures ou des reçus pour mon abonnement ?Existe-t-il des remises spéciales pour les clients fidèles ou les organisations à but non lucratif ?Comment fonctionne le processus de mise à niveau vers un abonnement supérieur ?Pouvez-vous m'expliquer la politique de sécurité entourant les informations de mon abonnement ?Y a-t-il des frais pour l'ajout de fonctionnalités ou de modules complémentaires à mon abonnement ?Comment puis-je accéder à un support client prioritaire en tant qu'abonné ?Quels sont les canaux de communication disponibles pour obtenir de l'aide concernant mon abonnement ?Comment puis-je résilier mon abonnement et quelles sont les étapes à suivre ?Pouvez-vous me fournir un résumé de toutes les modifications récentes apportées à mon abonnement ?Comment je peux payer ma facture d'hébergement ?Quels sont les trucs sympas que j'ai avec mon abonnement ?Est-ce que je peux changer mon abonnement pour un truc plus gros si j'ai besoin de plus de ressources ?Si je décide de quitter votre service, comment est-ce que je peux résilier mon abonnement ?Vous pouvez m'expliquer comment ça marche avec les factures et les paiements automatiques ?Qu'est-ce qui se passe si je veux ajouter un autre site web à mon abonnement ?Est-ce qu'il y a des frais cachés que je devrais connaître ?Si je veux passer à un abonnement annuel au lieu de mensuel, comment est-ce que je peux faire ça ?Comment est-ce que je peux vérifier la date de renouvellement de mon abonnement ?Vous pouvez me dire s'il y a des réductions spéciales pour les clients fidèles comme moi ?"))
# print(find_language("Qui est Albator, et quel est son rôle dans l'univers de la science-fiction ?Quelle est l'histoire principale du manga Albator ?Quels sont les principaux antagonistes auxquels Albator doit faire face ?Comment Albator est-il devenu le capitaine du vaisseau spatial Arcadia ?Pouvez-vous me donner une brève biographie du personnage d'Albator ?Quelles sont les caractéristiques physiques d'Albator ?De quel équipage Albator est-il entouré à bord de l'Arcadia ?Quelles sont les valeurs et les motivations d'Albator en tant que personnage ?Comment se déroulent les aventures d'Albator dans l'espace ?Quelle est la signification du crâne qui orne le navire Arcadia d'Albator ?Y a-t-il des relations amoureuses ou des intérêts romantiques dans l'histoire d'Albator ?Quels sont les éléments de science-fiction les plus marquants dans le monde d'Albator ?Quelles sont les séries dérivées ou les spin-offs mettant en scène Albator ?Comment l'univers d'Albator a-t-il évolué depuis sa création ?Y a-t-il des différences significatives entre le manga original d'Albator et les adaptations animées ?Quels sont les vaisseaux spatiaux les plus emblématiques de la série Albator ?Qui est l'auteur du manga Albator et quelle est son histoire ?Comment Albator est-il devenu un pirate de l'espace ?Quelles sont les technologies avancées présentes dans l'univers d'Albator ?Comment le personnage d'Albator a-t-il influencé la culture populaire ?Quelles sont les valeurs morales ou philosophiques véhiculées par Albator ?Y a-t-il des antagonistes récurrents dans l'histoire d'Albator ?Comment Albator a-t-il acquis sa renommée de corsaire de l'espace ?Quels sont les épisodes ou les arcs narratifs les plus mémorables d'Albator ?Quelle est la planète d'origine d'Albator, et quel rôle joue-t-elle dans l'histoire ?Comment le personnage d'Albator a-t-il évolué au fil des différentes adaptations ?Y a-t-il des éléments mythologiques ou symboliques associés à Albator ?Quels sont les conflits interstellaires les plus importants auxquels Albator a participé ?Quels sont les ennemis les plus redoutables auxquels Albator a dû faire face ?Comment Albator gère-t-il la pression en tant que pirate de l'espace ?Quels sont les pouvoirs ou les compétences spéciales d'Albator ?Y a-t-il des alliances ou des partenariats importants dans l'univers d'Albator ?Comment les thèmes de la liberté et de la rébellion sont-ils abordés dans Albator ?Quelles sont les influences culturelles ou artistiques qui ont inspiré Albator ?Comment les fans de la série célèbrent-ils Albator et son univers ?Quelles sont les différences entre les adaptations d'Albator dans les pays occidentaux et au Japon ?Comment le personnage d'Albator a-t-il évolué depuis sa première apparition ?Y a-t-il des hommages ou des références à Albator dans d'autres œuvres de fiction ?Quels sont les éléments de design les plus emblématiques d'Albator ?Comment les valeurs de courage et de loyauté sont-elles représentées dans Albator ?Quelles sont les relations entre Albator et les membres de son équipage ?Comment la musique accompagne-t-elle l'histoire d'Albator ?Quelle est la signification du crâne que porte Albator en tant que symbole ?Quels sont les thèmes sociaux ou politiques abordés dans Albator ?Comment les technologies futuristes sont-elles dépeintes dans Albator ?Quels sont les moments les plus émotionnels ou dramatiques de la série Albator ?Comment Albator se compare-t-il à d'autres héros de la science-fiction ?Quels sont les messages clés que les créateurs d'Albator ont souhaité transmettre ?Comment le personnage d'Albator a-t-il évolué au fil des adaptations modernes ?Comment Albator a-t-il réussi à devenir un personnage emblématique de la culture geek ?"))
print(find_language("Harlock, also known as Captain Albator in French.Is an emblematic character from the world of Japanese comics (manga) and animation.Created by Leiji Matsumoto, Harlock made his first appearance in 1977 in the manga 'Harlock 78'.The manga was adapted into an anime series of the same name, which first aired in 1978 in Japan.Leiji Matsumoto, the creator of Harlock, is a renowned mangaka (manga author) in Japan.He is also the author of other popular science fiction works.Such as 'Galaxy Express 999' and 'Space Battleship Yamato' (known as 'Le Cuirassé de l'espace' in France).Harlock is a charismatic space pirate who sails aboard his legendary ship, the Arcadia.He fights against malicious enemy forces, to protect Earth and humanity.The character Harlock is often depicted with his coat, hat and eyepatch, making him recognizable.The Harlock universe is set in the distant future where humanity has colonized space and interstellar conflicts are commonplace.Harlock himself is a solitary and stoic anti-hero, driven by a deep sense of freedom, justice and duty to humanity.His ship, the Arcadia, is a powerful war machine, equipped with advanced technologies and formidable weaponry.Harlock's story explores deep themes such as freedom, loyalty, rebellion against oppression, and the value of individualism.The stories feature complex moral dilemmas and existential questions, which helped make the series appealing to adult audiences."))
print(find_language("Although children were also captivated by Captain Harlock's space adventures.In addition to the original 'Harlock 78' series, Harlock has been adapted into several other animated series, films, and spin-off manga.The character has become an icon of popular culture in Japan and around the world, and he has continued to be revisited and celebrated in new adaptations over the years.Harlock is a classic example of the lasting impact a manga and anime character can have.The story begins in 2977 (2980 in the French version), at that time the land was swimming in opulence and welfare.This prosperous period is explained by the exploitation of the resources of other planets.All production is redistributed free of charge to the population.This ease of life taken to the extreme makes man lazy and cowardly.No longer needing to make the slightest effort for its survival, its behavior is similar to that of cattle.Television hardly helps things; it serves to monopolize people's attention to prevent them from thinking.It also allows the thoughts of those in power to be conveyed, stifling the little critical spirit that still remains in this decadent population.When a mysterious black sphere crashes onto earth, destroying part of the capital, the politicians who did nothing to warn the population prefer to ignore it.The ideograms written on it, however, betray its extraterrestrial origin. The government prefers to publicly accuse Harlock (Harlock) making him responsible for this attack.It must be said that he is an ideal scapegoat, because he is already unfavorably known for having attacked numerous Earth freighters.Harlock is indeed an outlaw, sickened by the generalized stupidity into which the inhabitants of the earth have plunged, he preferred to flee into space aboard the Altlantis.With this spaceship, he attacks cargo ships to collect seeds in preparation for the day when earthlings wake up and decide to cultivate the soil of their planet to live.If Harlock is still concerned about the fate of his home planet, it is because Stellie, his goddaughter, lives on Earth."))
print(find_language("Stellie does not exist in the manga; it was the director Rintarô who insisted on creating this character. Stellie is the daughter of Emeraldas and Toshirô, two close friends of Harlock.When they died, he promised them that Stellie would be raised on Earth and it is for this reason that he watches over both Stellie and the planet that welcomes her.Harlock wants to understand where this black sphere comes from and what its use is. He will discover that this object is in reality a beacon which serves to guide the Sylvidres towards the land which they intend to colonize.These extraterrestrials resemble human women in appearance, with the difference that their organism is plant and not animal like ours, their scouts can therefore blend into the Earth population without being spotted.Harlock's task is therefore very delicate because he must stop both attackers coming from space and those who are already on earth.Not to mention the fact that he must also fight against his own people, in particular Vilak (Mitsuru Kiruta), the Earth Minister of Defense, one of the rare Earth people who has not sunk into laziness and corruption.The Sylvidres once colonized Earth (and probably terraformed it) to make it a host planet on which they could take refuge when the sun of their mother planet went out.So they are not fundamentally bad or belligerent, they just have no choice, it's a question of survival, who can blame them?Moreover, as human beings appeared on Earth well after their arrival, ultimately, it is the Earthlings who are in reality the invaders. For once, the man is not the good guy in the story.Unlike Harlock 84 where the Humanoids are all bad (they are all eradicated at the end), in Harlock 78, the Sylvidre people are more nuanced.Indeed, there are internal differences between civilians and military, voices raised to leave humans in peace and seek another planet than Earth.These internal problems explain why Harlock remains alive despite the power of the Royal Armada. Queen Sylvidra wants to let Harlock live to focus the energy of her troops on a common adversary, which limits internal conflicts.It's very subtle for a children's series and it gives a little credibility to the fact that Harlock always gets away with it."))
