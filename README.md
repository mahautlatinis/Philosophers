# philosophers 📚

- Actual Status : validated.
- Result        : 100% (validated 28/08/2022)

<img src="https://github.com/42cursus/Philosophers/blob/master/philosophers.gif" width="80%">


Documentation sur les threads super interessante :

→ [http://pficheux.free.fr/articles/lmf/threads/](http://pficheux.free.fr/articles/lmf/threads/)

Un *thread* ressemble fortement à un processus fils classique à la différence qu'il partage beaucoup plus de données avec le processus qui l'a créé:

- Les variables globales
- Les variables statiques locales
- Les descripteurs de fichiers (file descriptors)

## Grille de correction la plus récente

[Intra_Projects_Philosophers_Edit.pdf](Philosophers%20c738ad237ae243d4afe96b8eeb3ff104/Intra_Projects_Philosophers_Edit.pdf)

You should protect the fork state using a mutex for each of them

Pour vérifier si on a des datas races, ajouter lors de la compilation le flag : 

-fsanitize=thread

## Notion importante : deadlock

Deadlock is **a permanent blocking of a set of threads** that are competing for a set of resources.

[https://www.youtube.com/watch?v=uA8X5zNOGw8](https://www.youtube.com/watch?v=uA8X5zNOGw8)

[https://cdn.discordapp.com/attachments/762995022802845737/859770404121477130/philosophers_correction_sheat1.png](https://cdn.discordapp.com/attachments/762995022802845737/859770404121477130/philosophers_correction_sheat1.png)
