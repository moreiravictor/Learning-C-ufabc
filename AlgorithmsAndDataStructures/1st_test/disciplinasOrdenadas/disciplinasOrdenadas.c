#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct subject_s {
    int cod;
    char *name_subject;
    int credits;
    struct subject_s *requisite;
} subject;

typedef struct course_s {
    int cod_course;
    char *name_course;
    subject *last_subject;
} course;

subject * createSubject(int cod, char *name_subject, int credits) {
    subject *new = malloc(sizeof(subject));
    new->cod = cod;
    new->name_subject = malloc(9999);
    strcpy(new->name_subject, name_subject);
    new->credits = credits;
    new->requisite = NULL;
    return new;
}

course * createCourse(int cod_course, char *name_course) {
    course *new = malloc(sizeof(course));
    new->cod_course = cod_course;
    new->name_course = malloc(9999);
    strcpy(new->name_course, name_course);
    new->last_subject = NULL;
    return new;
}

void imprime (course *c) {
    printf ("Disciplinas do curso: cod=%d nome=%s\n",
    c->cod_course, c->name_course);
    subject *d = c->last_subject;
    while (d != NULL) {
        printf ("cod=%d nome=%s cred=%d\n", d->cod, d->name_subject, d->credits);
        d = d->requisite;
    }
}

void insertSubject(course *course, subject *sub) {
    if (course->last_subject == NULL) {
        course->last_subject = sub;
    }
    else {
        subject *current = course->last_subject;
        subject *before = NULL;
        while(current != NULL && strcmp(sub->name_subject, current->name_subject) < 0) {
            before = current;
            current = current->requisite;
        }
        if(current == NULL) {
            before->requisite = sub;
        }
        else if (current == course->last_subject ) {
            sub->requisite = current;
            course->last_subject = sub;
        } 
        else {
            before->requisite = sub;
            sub->requisite = current;
        }
    }

}

int main () {
    int cod_curso;
    char nome_curso[100];
    scanf ("%d", &cod_curso);
    scanf ("%s", nome_curso);
    course *c = createCourse(cod_curso, nome_curso);

    int cod, creditos;
    char *nome = NULL;
    while (scanf ("%d", &cod) != EOF) {
        nome = malloc (100);
        scanf ("%s %d", nome, &creditos);
        subject *d = createSubject(cod, nome, creditos);
        insertSubject(c, d);
    }
    imprime (c);
    return 0;
}