RAKOTOARIVONY Allan
TP1 M3DS
----------------------------------------------------------------
Question 6
Pour dessiner les deux triangles, changer glDrawArrays(GL_TRIANGLES,0,3) en glDrawArrays(GL_TRIANGLES,0,6) dans la methode draw pour qu'il prenne en compte les 6 sommets

Question 7
VBO: Vertex Buffer Object : c'est une zone mémoire OpenGL identifié par un entier
VAO: Vertex Array Object : indique les valeurs des attributs du vertex shader actif lors du tracé
Program Shader:porgramme qui contient un vertex shader et un fragment shader qu'il faut donner à openGL pour paramétrer une partie du processus de rendu

Question 8
A - Il faut respecifier le fichier simple.frag pour lui dire quelle couleur affecter à chaque fragment
B - Dans simple.vertex, i faut ajouterles couleurs en entré et en sortie
C - créer un vbo pour le tableau de couleur de sommets dans initTriangleBuffer
D - faire la correspondance entre numero d'attribut/nom lors de l'initialisation du program shader dans initProgram
E - faire la correspondance numero d'attribut/VBO dans le vao

Question 9
Nouvelle image obtenu : media/snapshot/capture_0001.jpg
onpeGL dessine un triangle avec les 3 sommets qu'il rencontre, ensuite les 3 suivants. Donc ici les triangles changent de sommet.

Question 10
Pour retrouver les deux triangles précédents, il faut tracer les sommets dans l'ordre : 0,3,2,5,1,4

Question 11
media/snapshot/capture_0002.jpg

Question 12
On remarque que les couleurs de sommets ne sont pas les mêmes qu'avant même si on a bien les triangles.
L’ordre des indices de GL_ELEMENT_ARRAY_BUFFER s'applique uniquement sur l'ordre de traçage des sommets mais l'affectation des couleurs est le même que dans l'ordre de décalration de tableau de sommet et tableau de couleur

Question 13
media/snapshot/capture_0003.jpg

Après modif : 
media/snapshot/capture_0004.jpg
Le sommet 2 est vert des deux côtés. Ici, le sommet 2 a la couleur vert et quand on veut le dessiner dans le 2eme triangle, il conserve sa couleur verte


Question 14
media/snapshot/capture_0005.jpg

Question 15
media/snapshot/capture_0006.jpg

Question 16
media/snapshot/capture_0007.jpg

Question 17
Triangle position prend 8 sommets
On ne trace que 8 sommets
media/snapshot/capture_0008.jpg

Question 18
Il n'y a rien à modifier pour VBO(on lui donne déjà la taille des triangle_position en paramètre),VBA et VertexShader

Question 19
media/snapshot/capture_0009.jpg

Question 20
media/snapshot/capture_0011.jpg

Question 21/22/23
Modifier le vertex shader pour prendre en compte les coordonnées des texels.(prendre en in et mettre en out pour les fragments)
Modifier le fragment shader en utilisant uniform Sampler2D et les couleurs qu'on fait sortir sont : texture2D(texUnit,fTexCoord)
Pour le VBO dans init buffer: "	glGenBuffers(1,&_triangleTexCoordBuffer);
  		glBindBuffer(GL_ARRAY_BUFFER,_triangleTexCoordBuffer);
  		glBufferData(GL_ARRAY_BUFFER,_triangleTexCoord.size()*sizeof(float),_triangleTexCoord.data(),GL_STATIC_DRAW); "
dans initProgram :   "glBindAttribLocation(program,2,"texCoord");"
Dans le VAO : "	glBindBuffer(GL_ARRAY_BUFFER,_triangleTexCoordBuffer);
 		glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,0,0);
		glEnableVertexAttribArray(2); "

Question 24
Changer le coordonées de la texture tex : _triangleTexCoord = {
					       0,0,
					       0,1,
					       1,0,
					       1,1
					     };


Doit contenir :
- ce que vous n'avez pas fait (et pourquoi).
- difficultés rencontrées.
- commentaires éventuels sur le TP (points à éclaircir, longueur du sujet, etc). 
