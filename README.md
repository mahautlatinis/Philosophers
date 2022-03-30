# philosophers 📚

- Actual Status : validated.
- Result        : 100% (validated 28/08/2022)

[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com)

![Alt text](/philo.png?raw=true "Test")

Eating, thinking, sleeping

Documentation sur les threads super interessante :

→ [http://pficheux.free.fr/articles/lmf/threads/](http://pficheux.free.fr/articles/lmf/threads/)

Un *thread* ressemble fortement à un processus fils classique à la différence qu'il partage beaucoup plus de données avec le processus qui l'a créé:

- Les variables globales
- Les variables statiques locales
- Les descripteurs de fichiers (file descriptors)

## Grille de correction la plus récente

[Intra_Projects_Philosophers_Edit.pdf](Philosophers%20c738ad237ae243d4afe96b8eeb3ff104/Intra_Projects_Philosophers_Edit.pdf)

## Nouvelles fonctions

- **gettimeofday**
- **pthread_join**
- **pthread_mutex_init**
- **~~pthread_mutex_destroy~~**
- **pthread_mutex_lock**
- **pthread_mutex_unlock**

You should protect the fork state using a mutex for each of them

each philosopher should be a thread

Pour vérifier si on a des datas races, ajouter lors de la compilation le flag : 

-fsanitize=thread

## Notion importante : deadlock

Deadlock is **a permanent blocking of a set of threads** that are competing for a set of resources.

[https://www.youtube.com/watch?v=uA8X5zNOGw8](https://www.youtube.com/watch?v=uA8X5zNOGw8)

[https://cdn.discordapp.com/attachments/762995022802845737/859770404121477130/philosophers_correction_sheat1.png](https://cdn.discordapp.com/attachments/762995022802845737/859770404121477130/philosophers_correction_sheat1.png)
