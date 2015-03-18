Marechal Tanguy
Rakotoarivony Allan

Doit contenir :
- ce que vous n'avez pas fait (et pourquoi).
- difficultés rencontrées.
- commentaires éventuels sur le TP (points à éclaircir, longueur du sujet, etc). 

V direction du regard
L direction de la source de lumière
N normale au point observé

Le sol semble plus obscur avec l'éclairement par index car les sommets sont sombres et l'interplation rend le sol sombre

On ne voit pas la texture sur le fond de la scène car il n'y a pas d' objet : pas de sommet de triangle affiché, pas de plaquage de texture
En haut à droite car :  gl_position entre -1 et 1 alors que image texture entre O et 1 donc tout ce qui est entre -1 et 0 , il n'y a rien
ne bouge pas : REPÈRE DE TEXTURE EST SUR LE REPÈRE DE L'OEIL (coordTex = MTexture->Eye * glPosition et c'est comme MTexture->Eye = identity)


fTexCoord=vec4(position,1) => la texture est fixe par rapport aux objets car ((coordTex = MTexture->local * position et c'est comme si on fixait la texture à chaque reprère local)
fTexCoord=positionEye => le texture est sur l'oeil

