
typedef struct listaEncadeada
{
    int valor;
    struct listaEncadeada *prox;
} Lista;
/* Forma de utilização >> Lista *lista = novaLista();*/
Lista* novaLista()
{
    return NULL;
}
/* Forma de utilização >> listaVazia(Lista* lista);*/
int listaVazia(Lista* lista)
{
    return(lista == NULL);
}

/* Forma de utilização >> insere(lista, elem, pos);*/
Lista* insere(Lista* lista, int elem, int pos)
{
    if(pos < 1)/* Esta condição verifica se a posição é válida*/
        return lista;/* Se for inválida ela retorna a lista*/
    else
    {
        Lista *novo = (Lista*)malloc(sizeof(Lista));/* Aloca memória para o novo elemento da lista*/
        novo -> valor = elem;/* Insere o valor recebido no novo elemento da lista*/
        if(listaVazia(lista))/* Condição que verifica e a lista está vazia*/
        {
            /* Faz com que o novo elemento se torne o primeiro da lista*/
            novo -> prox = NULL;
            lista = novo;
        }
        else if(pos == 1)/* Senão verifica se a posição a ser inserida é a primeira*/
        {
            /* Faz com que o novo elemento se torne o primeiro da lista*/
            novo -> prox = lista;
            lista = novo;
        }
        else
        {
            int i;/*cria uma variável contador*/
            Lista *aux = lista;/* Cria um backup da lista atual*/
            /* Cria um laço para percorrer a lista até a posição desejada*/
            /* A condição do laço verifica se o ponteiro aponta pra NULL e o contador tem que parar uma posição antes da posição desejada*/
            for(i = 1 ; aux -> prox != NULL && i < pos -1 ; i++)
                aux = aux -> prox;
            /* Faz com que o novo elemento da lista aponte para o prox elemento de aux*/
            novo -> prox = aux -> prox;
            /* Faz com que aux aponte para novo*/
            aux -> prox = novo;
        }
    }
    return lista;
}

/* Forma de utilização >> recupera(lista, pos);*/
Lista* recupera(Lista* lista, int pos)
{
    int i = 1;/* Cria uma variável contador e a inicializa*/
    Lista *aux = lista;/* Cria um backup da lista atual*/
    /* Verifica se a lista está vazia e returna NULL caso esteja vazia*/
    if(listaVazia(lista))
        return NULL;
    /* Cria um laço para percorrer a lista até a posição desejada*/
    while(i < pos)
    {
        /* Navega até a posição desejada*/
        if(aux -> prox != NULL)
        {
            aux = aux -> prox;
            i++;
        }
        else
        {
            /* Exibe uma mensagem de erro caso não encontre a posição desejada*/
            printf("Posição inexistente na lista!\n");
            return NULL;
        }
    }
    return aux;/* Retorna o retorna o elemento da posição desejada*/
}
/* Forma de utilição remove(lista, pos);*/
Lista* remover(Lista* lista, int pos)
{
    /* Verifica se a lista está vazia*/
    if(listaVazia(lista))
        return NULL;
    if(pos == 1)
    {
        Lista *temp = lista;/* Cria um backup da lista*/
        lista = lista -> prox;/* Faz o início da lista ser o 2º elemento*/
        free(temp);/* Remove o primeiro elemento da lista*/
    }
    else
    {
        /* Cria dois ponteiros, um apontando para o 1º elemento e outro para o 2º*/
        Lista *aux = lista;
        Lista *temp = lista -> prox;
        /* Verifica se a lista só tem 1 elemento*/
        if(temp == NULL)
        {
            printf("Posição inexistente na lista!\n");
            return lista;
        }
        int i;/* Cria um contador*/
        /* cria um laço para percorrer a lista até a posição desejada*/
        for(i = 2 ; temp -> prox != NULL && 1 < pos ; i++)
        {
            temp = temp -> prox;
            aux = aux -> prox;
        }
        aux -> prox = temp -> prox;/* Refaz as ligações da lista*/
        free(temp);/* Remove o elemento desejado*/
    }
}
Lista* imprimeLista(Lista* lista)
{
    Lista* temp = lista;
    printf("\nOs dados na lista sao: ");
    do
    {
        printf("%d - ", temp -> valor);
        temp = temp -> prox;
    }while(temp != NULL);
    printf("\n");
}
