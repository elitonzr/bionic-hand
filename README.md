# bionic-hand

## Mão Biônica com Arduino e Servo Motores

Projeto de uma mão biônica impressa em 3D, controlada por um Arduino através de cinco servo motores.  
Os movimentos (gestos) são acionados via comunicação serial/Bluetooth, permitindo controlar a mão remotamente por um aplicativo ou outro dispositivo.

## Visão Geral

![bionic-hand.png](img/bionic-hand.png)

Este projeto controla uma mão biônica de 5 dedos usando:

- **Arduino** (UNO, Nano ou compatível)
- **5 servo motores** (um para cada dedo)
- **Estrutura da mão** impressa em **impressora 3D**
- **Módulo Bluetooth (opcional)** para envio de comandos sem fio

A mão é capaz de realizar vários gestos pré-programados, como:

- Abrir e fechar a mão
- Gesto de vitória (✌)
- Gesto de rock 🤘
- Gesto do Homem-Aranha 🕷🕸
- Hang Loose 🤙
- Representação de números de 1 a 5 com os dedos
- Uma sequência de demonstração automática

## Funcionalidades

- Controle individual dos 5 dedos por servo motores (usando um **array de servos** no código)
- Gestos pré-definidos acionados por caracteres recebidos na serial/Bluetooth
- Comandos aceitos em **maiúsculas e minúsculas** (por exemplo: `A` ou `a` para abrir)
- Inicialização com animação de abertura e fechamento da mão
- Feedback via monitor serial indicando o gesto atual

## Hardware Utilizado

- 1x Arduino (UNO, Nano, etc.)
- 5x Servo motores (SG90, MG90S ou similares)
- 1x Módulo Bluetooth (HC-05, HC-06 ou similar) – **opcional**, mas recomendado
- Fonte de alimentação adequada para os servos
- Estrutura da mão biônica impressa em 3D [link do Thingiverse](https://www.thingiverse.com/thing:1691704)
- Jumpers e protoboard (se necessário)

### Ligações dos Servos

![Vista esquemática.png](<img/Vista esquemática.png>)

No código, os servos dos dedos são representados por um **array**:

```cpp
Servo dedo[5];
```

E estão ligados às seguintes portas digitais:

- `dedo[0]` (Dedo 1) → **D2**
- `dedo[1]` (Dedo 2) → **D3**
- `dedo[2]` (Dedo 3) → **D4**
- `dedo[3]` (Dedo 4) → **D5**
- `dedo[4]` (Dedo 5) → **D6**

> **Importante:**  
> Não alimente todos os servos diretamente da porta 5V do Arduino se eles forem puxar muita corrente.  
> Use uma fonte externa 5V com GND comum ao Arduino.

### Conexão do Bluetooth (opcional)

Exemplo usando módulo HC-05:

- HC-05 TX → RX do Arduino  
- HC-05 RX → TX do Arduino (geralmente com divisor de tensão)  
- HC-05 VCC → 5V  
- HC-05 GND → GND  

> Você também pode usar a própria USB/Serial do Arduino para enviar os comandos pelo **Monitor Serial** da IDE.

## Software

### Dependências

- [IDE Arduino](https://www.arduino.cc/en/software)
- Biblioteca `Servo.h` (já vem incluída na IDE Arduino)

### Estrutura do Código

Trechos principais do código:

```cpp
#include <Servo.h>

Servo dedo[5];

int fecha = 180;
int abre = 0;

void setup()
{
  Serial.begin(9600);
  dedo[0].attach(2);
  dedo[1].attach(3);
  dedo[2].attach(4);
  dedo[3].attach(5);
  dedo[4].attach(6);

  gestoAbrir();
  delay(3000);

  gestoFechar();
  delay(3000);

  gestoAbrir();
  delay(3000);
}
```

A função responsável por aplicar qualquer gesto é:

```cpp
void aplicaGesto(int d0, int d1, int d2, int d3, int d4)
{
  int valores[5] = {d0, d1, d2, d3, d4};
  for (int i = 0; i < 5; i++)
  {
    dedo[i].write(valores[i]);
  }
}
```

Cada gesto chama `aplicaGesto()` com os ângulos de cada dedo (aberto ou fechado), por exemplo:

```cpp
void gestoAbrir()
{
  aplicaGesto(abre, abre, abre, abre, abre);
  Serial.println("Mão Aberta!");
}

void gestoFechar()
{
  aplicaGesto(fecha, fecha, fecha, fecha, fecha);
  Serial.println("Mão Fechada!");
}
```

## Mapeamento dos Comandos

Os gestos são acionados por caracteres recebidos via serial/Bluetooth.  
O código aceita **maiúsculas e minúsculas** para os comandos de letras:

- `A` ou `a` → **Abrir** a mão  
- `F` ou `f` → **Fechar** a mão  
- `V` ou `v` → Gesto de **Vitória** (✌)  
- `R` ou `r` → Gesto de **Rock** (🤘)  
- `S` ou `s` → Gesto do **Aranha**  
- `H` ou `h` → Gesto **Hang Loose** (🤙)  

Comandos numéricos:

- `'1'` → Gesto **Número 1**  
- `'2'` → Gesto **Número 2**  
- `'3'` → Gesto **Número 3**  
- `'4'` → Gesto **Número 4**  
- `'5'` → Gesto **Número 5**  

### Sequência de Demonstração

O caractere `T` ou `t` dispara uma **sequência automática de demonstração**, que executa:

1. Gestos de número 1 até 5  
2. Fecha a mão  
3. Abre a mão  
4. Vitória  
5. Rock  
6. Aranha  
7. Hang Loose  
8. Abre a mão novamente

Essa sequência é ideal para apresentações do projeto.

## Como Usar

1. **Monte** a mão biônica 3D e fixe os servos em cada dedo.
2. **Conecte** os servos ao Arduino conforme o mapeamento de pinos.
3. **Carregue** o código na placa usando a IDE Arduino.
4. Abra o **Monitor Serial** (ou conecte o módulo Bluetooth a um app de terminal).
5. Configure o monitor serial para:
   - **Baud rate**: `9600`
   - **Final de linha**: `No line ending`
6. Envie os caracteres listados na seção de comandos (`A`, `F`, `V`, `R`, `S`, `H`, `1` a `5`, `T`) e observe a mão executando os gestos.

## Projeto no Tinkercad

Você pode visualizar/experimentar o circuito também no Tinkercad:

[Projeto no Tinkercad – bionic-hand](https://www.tinkercad.com/things/dSHOwrBsTty-bionic-hand)

## Possíveis Melhorias

- Adicionar calibração individual de abertura/fechamento por dedo
- Suavizar os movimentos dos servos (animação com passos intermediários)
- Criar um aplicativo para Android para enviar os comandos via Bluetooth
- Integrar sensores (flex, EMG, etc.) para controle mais natural
- Adicionar novos gestos personalizados

## Licença

- MIT  

```text
Este projeto está licenciado sob os termos da licença MIT.  
Consulte o arquivo LICENSE para mais detalhes.
```
