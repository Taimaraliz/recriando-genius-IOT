# EXPLORANDO O JOGO DA MEMÓRIA "GENIUS" COMO FERRAMENTA DE ENSINO E REABILITAÇÃO DOS MOVIMENTOS PARA CRIANÇAS E ADOLESCENTES

📌 Versão
1.0

### 🚀 Informações Gerais:
Criado como projeto final da disciplica "OBJETOS INTELIGENTES CONECTADOS" do curso de Analise de Desenvolvimento de Sistema - Universidade Presbiteriana Mackenzie.

Este projeto tem como objetivo desenvolver e implementar o jogo "Genius" como uma eficaz ferramenta de ensino para crianças e adolescentes. Também é pensado como auxilio a recuperação dos movimentos, tranalho da memória e cognição. Pois acredito que enfrentar o desafio proposto pelo jogo, que envolve pensar rapidamente e repetir sequências de luzes e sons, não apenas proporciona diversão, mas também contribui significativamente para o desenvolvimento da memória e
aprendizagem dos jovens jogadores. 
Este trabalho explora como a integração do "Genius" no contexto educacional pode ser uma abordagem eficiente e envolvente para estimular o crescimento cognitivo durante a infância e
adolescência.


### 🛠️ Construido com:
 * Linguagem C++
 * ESP32 - para monitoramento de batimentos cardíacos wireless, combinado com o 
 * sensor HCSR04
 * 1 Protoboard (mín.820 pinos)
 * 4 resistores de 300 ohms;
 * 4 Pushbuttons
 * 1 buzzer como atuador para alertas. 
 * 4 leds de Cores Diferentes (azul, vermelho, amarelo e verde)
 * 26 Jumpers macho-macho
 * 8 Resistências elétricas de 10kΩ
 * desenvolvimento feito na IDE do Arduino, empregando programação específica para integrar   hardware e software
 * comunicação via MQTT para transmissão de dados em tempo real para a plataforma Ubidots.


🔧 Instalação

⌨️ - Baixar a IDE do Arduino:
Acesse o site oficial do Arduino. Navegue até a seção de downloads e escolha a versão da IDE do Arduino compatível com seu sistema operacional (Windows, macOS ou Linux). Exemplo de instalação da IDE:

- Windows: Execute o instalador baixado e siga as instruções na tela. Certifique-se de instalar todos os drivers necessários durante o processo de instalação. 
- macOS: Abra o arquivo .zip baixado e arraste o aplicativo Arduino para a pasta "Aplicativos". - Linux: Descompacte o arquivo baixado e execute o script de instalação. Verificar a Instalação:

Abra a IDE do Arduino para garantir que foi instalada corretamente. Configurando a ESP32 na IDE do Arduino Adicionar o URL do Gerenciador de Placas para a ESP32:

Na IDE do Arduino, vá até "Arquivo" > "Preferências". No campo "URLs Adicionais de Gerenciadores de Placas", insira o seguinte URL para o pacote da ESP32:

[Doc. estilo de formatação](https://dl.espressif.com/dl/package_esp32_index.json)


### Instalar a Placa ESP32:
Navegue até "Ferramentas" > "Placa:" > "Gerenciador de Placas". Na janela do Gerenciador de Placas, digite "ESP32" na barra de pesquisa. Encontre o pacote chamado "esp32 by Espressif Systems" e clique em "Instalar".

⌨️ - Selecionar a Placa ESP32:
 Após a instalação, vá para "Ferramentas" > "Placa:" e selecione o modelo específico da sua ESP32 na lista de placas disponíveis.

 - Conectar a ESP32 ao Computador:
   Use um cabo micro USB para conectar a ESP32 à porta USB do seu computador.

- Vá para "Ferramentas" > "Porta" e selecione a porta COM que aparece com o nome da sua ESP32.   Se você não tem certeza de qual porta selecionar, desconecte a placa, abra o menu novamente para ver as portas listadas, reconecte a placa e veja qual nova porta aparece.

- Abra qualquer exemplo básico. Vá até  "Arquivo" > "Exemplos" > "01.Basics" > "Blink". 
- Clique no ícone de "Upload" (seta para a direita) na barra de ferramentas da IDE para carregar o sketch na sua ESP32. 

###### observação:
 Observe se o LED na placa está piscando, isso indica que o programa está sendo executado corretamente. Após o teste, faça upload do código "code-esp32".


### Modelo de Montagem

![Imagem da protoboard montada](/img/montagem.png) 


⚙️ Executando os testes
Explicar como executar os testes automatizados para este sistema.

🔩 Analise os testes de ponta a ponta
Explique que eles verificam esses testes e porquê.


⌨️ E testes de estilo de codificação
Explique que eles verificam esses testes e porquê.




### ✒️ Discente:
#### Taimara Liz de Souza


### Docentes:
#### Cristiano Morais de Souza
#### Luiz Carlos Machi Lozano






🎁 Expressões de gratidão

⌨️ com ❤️ por Armstrong Lohãns 😊
