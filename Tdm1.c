#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> // pour les types pid_t, uid_t, gid_t

void print_PCB()
{
    // Récupération des informations du processus courant
    pid_t pid = getpid();   // PID du processus
    pid_t ppid = getppid(); // PPID du processus parent
    uid_t uid = getuid();   // UID de l'utilisateur effectif
    gid_t gid = getgid();   // GID du groupe effectif

    // Affichage des informations dans le format demandé
    printf("PCB | PPID: %d\n", ppid);
    printf("    | PID: %d\n", pid);
    printf("    | UID: %d\n", uid);
    printf("    | GID: %d\n", gid);
}


/*int main()
{
    pid_t ret = fork(); // Création d'un nouveau processus
    printf("fork() has returned: %d\n", ret);
    print_PCB(); // Appel de la fonction pour afficher les informations
    exit(EXIT_SUCCESS);
}*/

/*int main() {
    int nb_fork = 0; // Compteur du nombre de forks réussis

    while (1) {
        pid_t ret = fork(); // Crée un nouveau processus

        if (ret == 0) {
            // Processus fils
            nb_fork++;       // Incrémente le compteur
            sleep(1);        // Attend une seconde
            exit(EXIT_SUCCESS); // Terminer le processus fils
        } else if (ret < 0) {
            // Échec du fork
            perror("fork() failed");
            printf("Nombre total de forks réussis: %d\n", nb_fork);
            exit(EXIT_FAILURE); // Terminer avec une erreur
        }
        // Le processus père continue la boucle pour créer d'autres fils
        nb_fork++;
    }

    return EXIT_SUCCESS;
}*/

/*int main()
{
fork();fork();fork();
printf("fork !\n");
exit(EXIT_SUCCESS);
}*/

/*int main()
{
while(1) fork();
}*/


/*int main() {
    pid_t pid = fork();  // Crée un processus fils

    if (pid == -1) {
        // Si le fork échoue, afficher l'erreur et sortir
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Processus fils
        printf("Je suis le fils, je vais dormir 10 secondes...\n");
        sleep(10);  // Le fils dort pendant 10 secondes
        exit(123);  // Le fils se termine avec le code de sortie 123
    } else {
        // Processus père
        int status;
        printf("Je suis le père, j'attends la fin du fils...\n");

        // Le père attend la fin du fils
        wait(&status);

        // Vérifier si le fils s'est terminé normalement
        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            printf("Le fils s'est terminé normalement avec le code de sortie: %d\n", exit_status);
        } else {
            printf("Le fils ne s'est pas terminé normalement.\n");
        }
    }

    return 0;
}

*/

int main(int argc, char *argv[]) {
    if (argc < 2) {
        // Si aucun argument n'est passé, on affiche un message d'erreur
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Affiche un message de soumission à la commande
    printf("Yes, my master:\n");

    // Exécuter la commande en utilisant execvp
    if (execvp(argv[1], &argv[1]) == -1) {
        // Si execvp échoue, afficher une erreur
        perror("execvp failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}
