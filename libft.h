#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* ASCII TO INTEGER
converte una stringa rappresentante un numero intero nell'intero corrispondente.*/
int		ft_atoi(const char *str);


int		ft_bhqkb(void *lst, void (*f)(void *));

/* AZZERA MEMORIA
serve per azzerare i primi n byte dell'area di memoria a cui punta s.
utile per cancellare dati sensibili ed evitare che possano essere recuperati.*/
void	ft_bzero(void *s, size_t n);

/* CLEAN ALLOC
alloca memoria per un array di nmemb elementi, ognuno di size byte, e restituisce
un puntatore alla memoria allocata. A differenza di malloc inizializza la memoria
allocata impostando tutti i byte a zero.*/
void	*ft_calloc(size_t nmemb, size_t size);

/* SPLIT
divide la stringa in sottostringhe utilizzando il c come separatore. Restituisce un
array di puntatori a stringa contenente le sottostringhe separate.*/
char	**ft_split(const char *s, char c);

/* INTEGER TO ASCII
converte un numero intero nella stringa di caratteri corrispondente.*/
char	*ft_itoa(int n);

/* IS ALPHANUMERICAL
rsestituisce 1 se il carattere c è alfanumerico.*/
int		ft_isalnum(int c);

/* IS ALPHA
Restituisce 1 se il carattere c è una lettera.*/
int		ft_isalpha(int c);

/* IS ASCII
Restituisce 1 se il carattere c è un ascii. */
int		ft_isascii(int c);

/* IS DIGIT
Restituisce 1 se il carattere c è un numero.*/
int		ft_isdigit(int c);

/* IS PRINT
Restituisce 1 se il carattere c è stampabile.*/
int		ft_isprint(int c);

/* COPY MEMORY AREA
copia n byte dalla sorgente alla destinazione, ma richiede che le aree di memoria
sorgente e destinazione non si sovrappongano. Se si dovessero sovrapporre, il
comportamento sara' indefinito e potrebbero verificarsi errori.
Per gestire questa eventualità, è preferibile utilizzare memmove, che è garantito
per funzionare correttamente anche con aree di memoria sovrapposte.

Dato che void *dest è un PUNTATORE GENERICO e che per accedere ai singoli byte 
dei dati puntati da src e dest i puntatori devono essere castati a un tipo 
specifico utilizzo l'unsigned char che occupa un byte di memoria.
Con il cast (unsigned char *) si ottiene un puntatore che accede ai singoli byte 
dei dati anche se il tipo originale dei dati è sconosciuto.*/
void	*ft_memcpy(void *dest, const void *src, size_t n);

/* RICERCA MEMORIA CARATTERE
All'occorrenza di c all'interno della str puntata da *s ritorna il 
puntatore void al primo byte uguale a c che dovrà essere 
convertito dal chiamante nel tipo appropriato.*/
void	*ft_memchr(const void *s, int c, size_t n);

/* MEMORY COMPARE
confronta due aree di memoria byte per byte e restituisce un intero
che indica se i primi n byte di s1 sono meno, uguali o maggiori di quelli dei
primi n byte di s2.

Non utilizzare memcmp per confrontare dati critici per la sicurezza, come segreti
crittografici, è vurnerabile agli attacchi di analisi temporale.
Il tempo necessario per eseguire il confronto dipende dal numero di byte uguali
nelle due aree di memoria. Questo comportamento può essere sfruttato dagli
attaccanti per determinare i byte corretti tramite analisi temporale.
	Per esempio, supponiamo che un attaccante abbia accesso ad un canale non
	sicuro per misurare il tempo impiegato per eseguire il confronto di una parte
	dei dati critici con un valore di riferimento. Se il confronto è più veloce,
	ciò suggerirebbe che la corrispondenza sia diversa, mentre se è più lento,
	ciò suggerirebbe che la corrispondenza sia uguale. e cosi' un attaccante può
	determinare gradualmente tutti i byte dei dati critici.
Per evitare questo tipo di attacco, è necessario utilizzare una funzione che
esegua confronti in tempo costante, dove il tempo necessario per eseguire il
confronto non dipende dalla presenza di byte corrispondenti. Questo può essere
fatto con il blind hashing o utilizzando funzioni di confronto specificamente
progettate per garantire tempi uniformi, come consttime_memequal() in NetBSD.*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/* COPY MEMORY AREA
e' quella che dovresti usare al posto di memcpy perche' qui se le aree di memoria
si sovrappongono la copia dei byte avviene dalla fine verso l'inizio cosi da non
sovrascrivere i byte che ancora devono essere copiati.*/
void	*ft_memmove(void *dest, const void *src, size_t n);

/* MEMORY SET
e' simile a bzero solo che riempie i primi n byte dell'area di memoria puntata
da s con c anziche' con lo zero.

Quando la funzione viene chiamata, il puntatore void viene implicitamente 
convertito nel tipo di puntatore appropriato dal compilatore in base
al tipo del puntatore passato alla funzione.*/
void	*ft_memset(void *s, int c, size_t n);

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstadd_front(t_list **lst, t_list *new);

void	ft_lstclear(t_list **lst, void (*del)(void *));

void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

/* PUTCHAR FD
è simile a putchar in quanto scrive un singolo carattere, ma permette di
specificare il file descriptor su cui scrivere, non limitandosi solo a stdout.*/
void	ft_putchar_fd(char c, int fd);

/* PUTENDL FD
scrive la stringa s sul file descriptor specificato e poi aggiunge un carattere
di nuova riga, garantendo che la riga successiva inizi su una nuova linea.*/
void	ft_putendl_fd(char *s, int fd);

/* PUTNBR FD
prende in input un intero n e un file descriptor fd e scrive la rappresentazione
testuale dell'intero n sul file descriptor specificato.*/
void	ft_putnbr_fd(int n, int fd);

/* PUTSTR FD
scrive la stringa sul file descriptor specificato.*/
void	ft_putstr_fd(char *s, int fd);

/* ITERATORE STRINGA
applica la funzione f a ciascun carattere della stringa str, passando l'indice
di ciascun carattere come primo argomento alla funzione f. Questa funzione può
essere utile per eseguire operazioni su ciascun carattere di una stringa, ad
esempio per modificare i caratteri in base alla loro posizione all'interno della
stringa. Può essere utilizzata per contare i caratteri che soddisfano determinati
criteri. Può essere utilizzata per elaborare i dati contenuti nella stringa in
modo iterativo, ad esempio per calcolare somme, medie, deviazioni standard, o per
eseguire altre operazioni statistiche o analitiche.*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/* STRING DUPLICATE
crea una copia esatta della stringa str allocando dinamicamente la memoria
necessaria per contenere la copia e restituendo un puntatore ad essa.*/
char	*ft_strdup(char *src);

/* LOCATE CHARACTER IN STRING
cerca la prima occorrenza di un carattere specifico all'interno di una stringa e
restituisce un puntatore a tale carattere.*/
char	*ft_strchr(const char *s, int c);

/* STRING JOIN
crea una stringa che contiene il risultato della concatenazione e ritorna un
puntatore alla nuova stringa.*/
char	*ft_strjoin(char const *s1, char const *s2);

/* STRING MAP
applica una funzione a ciascun carattere di una stringa, passando anche l'indice
di quel carattere alla funzione. Il risultato di ogni applicazione della funzione
f viene utilizzato per costruire una nuova stringa che viene restituita alla fine*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* LOCATE SUBSTRING IN A STRING
cerca la prima occorrenza della sottostringa little all'interno della stringa big
limitando la ricerca a non più di len caratteri.*/
char	*ft_strnstr(const char *big, const char *little, size_t len);

/* LOCATE CHARACTER IN STRING
restituisce un puntatore all'ultima occorrenza del carattere c nella stringa s.*/
char	*ft_strrchr(const char *s, int c);

/* STRING TRIM
elimina i caratteri specificati in set dall'inizio e dalla fine della stringa str.*/
char	*ft_strtrim(char const *s1, char const *set);

/* SUB STRING
restituisce una sottostringa di una stringa di input s, iniziando dalla posizione
start e con una lunghezza massima di len caratteri.

Se la posizione di partenza start supera la lunghezza totale della stringa di
input s, la funzione restituisce una stringa vuota. Se l'allocazione di memoria
per la sottostringa fallisce, la funzione restituisce NULL.*/
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* STRING LENGTH
restituisce la grandezza della stringa passatale come argomento.*/
size_t	ft_strlen(const char *str);

/* CONCATENA STRINGHE
concatena in modo sicuro due stringhe, assicurandosi che il risultato sia
NUL-terminato e che non superi la dimensione specificata del buffer size.*/
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/* STRING LENGHT COPY
copia la stringa src nella stringa dest fino alla dimensione specificata size.
La funzione assicura che la stringa dest sia terminata correttamente da un
carattere nullo e che non superi la dimensione specificata.*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

/* STRING COMPARE
confronta i primi n caratteri delle stringhe s1 e s2. Se una delle due stringhe
finisce prima di raggiungere n, la funzione si ferma al primo carattere di
terminazione di stringa trovato. Se tutte le n posizioni sono uguali, la
funzione restituisce 0. Se durante il confronto viene trovato un carattere
diverso nelle due stringhe, la funzione restituisce la differenza dei caratteri.*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* TO LOWER
converte il char in minuscolo.*/
int		ft_tolower(int c);

/* TO UPPER
converte il char in maiuscolo.*/
int		ft_toupper(int c);

#endif
