Rakotoarivony Allan

Doit contenir :
- ce que vous n'avez pas fait (et pourquoi).
- difficultés rencontrées.
- commentaires éventuels sur le TP (points à éclaircir, longueur du sujet, etc). 

7) C'est la couleur du dernier pixel dessiné qui est mémorisé.C'est pour cela que le rouge est invisible sur le dessin

8) Avec les opérations qu'on a fait (glDepthFunc(GL_LESS)), si l'ancienne couleur a une profondeur moins élevé, alors on ne l'ecrase pas. Ici rouge et bleu ont des profondeurs moins élevés

9) On a un écran blanc car au début, on a mis le depth des pixels à 1. Et il n'y a aucun pixel qui passe le test car depht_max_pixel = 1. Donc, rien n'est dessiné
   Si depth initial = 0, alors ce sont ceux qui ont le depth le plus élevé qui sont déssiné. Ici, ce sont les triangles vert et cyan
   Avec 0.5 de depth, on obtient un losange car les parties non dessinés ont un depth(calculés par interpolation)<0.5

10)

