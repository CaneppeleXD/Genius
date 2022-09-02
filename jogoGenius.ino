#define comecar 0

int pressionado = 0;

int botoes[] = {8, 9, 10, 11};

void setup()
{
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    for (int i = 0; i < sizeof(botoes); i++)
    {
        pinMode(botoes[i], INPUT_PULLUP);
    }
    Serial.begin(9600);
}

void loop()
{
    int sequencia[0];
    if (digitalRead(comecar) == HIGH)
    {
        int rodando = 1;
        delay(1000);
        rodada(sequencia);
        while (rodando == 1)
        {
            String estado == "esperando";
            if (estado.compareTo("esperando"))
            {
                for (int i = 0; i < sizeof(sequencia) && !estado.compareTo("errou"); i = i)
                {
                    if (botaopressionado(1) || botaopressionado(2)|| botaopressionado(3) || botaopressionado(4))
                    {
                        if (digitalRead(botaopressionado(sequencia[i]-1)))
                        {
                            estado = "acertou";
                            i++
                        }
                        else
                        {
                            estado = "errou";
                        }
                    }
                }
            }
            if(estado.compareTo("acertou"))
            {
                rodando = 0;
            }
        }
    }
}

void sortear(int sequencia[])
{
    int memoria[sizeof(sequencia)];
    for (int i = 0; i < sizeof(sequencia); i++)
    {
        memoria[i] = sequencia[i];
    }
    sequencia[sizeof(sequencia) + 1];
    for (int i = 0; i < sizeof(sequencia); i++)
    {
        sequencia[i] = memoria[i];
    }
    sequencia[sizeof(sequencia) - 1] = random(1, 4);
}

void rodada(int sequencia[])
{
    sortear(sequencia);
    for (int i = 0; i < sizeof(sequencia); i++)
    {
        digitalWrite(sequencia[i], HIGH);
        delay(500);
        digitalWrite(sequencia[i], LOW);
    }
}

boolean botaopressionado(botao){
    boolean retorno = false;
    if (digitalRead(botoes[botao]) == LOW && pressionado == false)
    {
        cimapressionado = true;
    }
    else if (digitalRead(botoes[botao]) == HIGH && pressionado == true)
    {
        retorno = true;
        cimapressionado = false;
    }
    return(retorno);
}
