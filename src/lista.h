
typedef struct listaEncadeada
{
    int valor;
    struct listaEncadeada *prox;
} Lista;
/* Forma de utiliza��o >> Lista *lista = novaLista();*/
Lista* novaLista()
{
    return NULL;
}
/* Forma de utiliza��o >> listaVazia(Lista* lista);*/
int listaVazia(Lista* lista)
{
    return(lista == NULL);
}

/* Forma de utiliza��o >> insere(lista, elem, pos);*/
Lista* insere(Lista* lista, int elem, int pos)
{
    if(pos < 1)/* Esta condi��o verifica se a posi��o � v�lida*/
        return lista;/* Se for inv�lida ela retorna a lista*/
    else
    {
        Lista *novo = (Lista*)malloc(sizeof(Lista));/* Aloca mem�ria para o novo elemento da lista*/
        novo -> valor = elem;/* Insere o valor recebido no novo elemento da lista*/
        if(listaVazia(lista))/* Condi��o que verifica e a lista est� vazia*/
        {
            /* Faz com que o novo elemento se torne o primeiro da lista*/
            novo -> prox = NULL;
            lista = novo;
        }
        else if(pos == 1)/* Sen�o verifica se a posi��o a ser inserida � a primeira*/
        {
            /* Faz com que o novo elemento se torne o primeiro da lista*/
            novo -> prox = lista;
            lista = novo;
        }
        else
        {
            int i;/*cria uma vari�vel contador*/
            Lista *aux = lista;/* Cria um backup da lista atual*/
            /* Cria um la�o para percorrer a lista at� a posi��o desejada*/
            /* A condi��o do la�o verifica se o ponteiro aponta pra NULL e o contador tem que parar uma posi��o antes da posi��o desejada*/
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

/* Forma de utiliza��o >> recupera(lista, pos);*/
Lista* recupera(Lista* lista, int pos)
{
    int i = 1;/* Cria uma vari�vel contador e a inicializa*/
    Lista *aux = lista;/* Cria um backup da lista atual*/
    /* Verifica se a lista est� vazia e returna NULL caso esteja vazia*/
    if(listaVazia(lista))
        return NULL;
    /* Cria um la�o para percorrer a lista at� a posi��o desejada*/
    while(i < pos)
    {
        /* Navega at� a posi��o desejada*/
        if(aux -> prox != NULL)
        {
            aux = aux -> prox;
            i++;
        }
        else
        {
            /* Exibe uma mensagem de erro caso n�o encontre a posi��o desejada*/
            printf("Posi��o inexistente na lista!\n");
            return NULL;
        }
    }
    return aux;/* Retorna o retorna o elemento da posi��o desejada*/
}
/* Forma de utili��o remove(lista, pos);*/
Lista* remover(Lista* lista, int pos)
{
    /* Verifica se a lista est� vazia*/
    if(listaVazia(lista))
        return NULL;
    if(pos == 1)
    {
        Lista *temp = lista;/* Cria um backup da lista*/
        lista = lista -> prox;/* Faz o in�cio da lista ser o 2� elemento*/
        free(temp);/* Remove o primeiro elemento da lista*/
    }
    else
    {
        /* Cria dois ponteiros, um apontando para o 1� elemento e outro para o 2�*/
        Lista *aux = lista;
        Lista *temp = lista -> prox;
        /* Verifica se a lista s� tem 1 elemento*/
        if(temp == NULL)
        {
            printf("Posi��o inexistente na lista!\n");
            return lista;
        }
        int i;/* Cria um contador*/
        /* cria um la�o para percorrer a lista at� a posi��o desejada*/
        for(i = 2 ; temp -> prox != NULL && 1 < pos ; i++)
        {
            temp = temp -> prox;
            aux = aux -> prox;
        }
        aux -> prox = temp -> prox;/* Refaz as liga��es da lista*/
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
