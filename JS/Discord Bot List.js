const lib = require('lib')({token: process.env.STDLIB_SECRET_TOKEN});

// Command option values are accessible in event.data.options
let providedOptionFields = context.params.event.data.options.map((option) => {
  let types = {
    '3': (opt) => { return `${opt.value}`; },
    '4': (opt) => { return `${opt.value}`; },
    '5': (opt) => { return `${opt.value}`; },
    '6': (opt) => { return `<@!${opt.value}>`; },
    '7': (opt) => { return `<#${opt.value}>`; },
    '8': (opt) => { return `<@&${opt.value}>`; },
    '9': (opt) => { return `${opt.value}`; },
  };
  return {
    name: `${option.name}`,
    value: `${types[option.type] ? types[option.type](option) : (option.value || 'none')}`,
  };
});

if (providedOptionFields.length) {
  let categoria = context.params.event.data.options[0].value;
  let pagina = context.params.event.data.options[1].value - 1;
  
  if(pagina >= 0 && pagina < numPaginas){
    switch(categoria){
      case "All":{
        let result = await lib.googlesheets.query['@0.3.0'].select({
          range: `A:F`,
          bounds: 'FIRST_EMPTY_ROW',
          where: [{}],
          limit: {
            'count': 0,
            'offset': 0
          }
        });
        
        let numItens = result.rows.length;
        let numPaginas = Math.ceil(numItens / 4);
        
        await lib.discord.channels['@0.0.6'].messages.create({
          channel_id: context.params.event.channel_id,
          content: "Aqui está sua lista:",
          tts: false,
          embed:{
            type: "rich",
            title: `Página ${pagina + 1} de ${numPaginas}`,
            description: "",
            color: 0x00FFFF
          }
        });
        
        for (let i = 0 + pagina * 4; i < 4 + 4 * pagina; i++){
          let mangas_nomes = result.rows[i].fields.titulo;
        
          let mangas_capitulo = result.rows[i].fields.ultimo_cap;
        
          let mangas_status = result.rows[i].fields.status;
        
          let mangas_url = result.rows[i].fields.url;
        
          let mangas_favorito = result.rows[i].fields.favorito;
          
          await lib.discord.channels['@0.0.6'].messages.create({
            "channel_id": `${context.params.event.channel_id}`,
            "content": "",
            "tts": false,
            "components": [
              {
                "type": 1,
                "components": [
                  {
                    "style": 5,
                    "label": "Link",
                    "url": `${mangas_url}`,
                    "disabled": false,
                    "type": 2
                  }
                ]
              }
            ],
            "embed": {
              "type": "rich",
              "title": "",
              "description": "",
              "color": 0x00FFFF,
              "fields": [
                {
                  "name": `${mangas_nomes}`,
                  "value": `Capítulo ${mangas_capitulo}`
                }
              ],
              "footer": {
                "text": `Status: ${mangas_status}`
                }
            }
          }); // END MESSAGE.CREATE
        } // END FOR LOOP
        break;
      } // END CASE ALL
      
      case "Favoritos":{
        let result = await lib.googlesheets.query['@0.3.0'].select({
          range: `A:F`,
          bounds: 'FIRST_EMPTY_ROW',
          where: [{'favorito__is': `sim`}],
          limit: {
            'count': 0,
            'offset': 0
          }
        });
        
        let numItens = result.rows.length;
        let numPaginas = Math.ceil(numItens / 4);
        
        await lib.discord.channels['@0.0.6'].messages.create({
          channel_id: context.params.event.channel_id,
          content: "Aqui está sua lista:",
          tts: false,
          embed:{
            type: "rich",
            title: `Página ${pagina + 1} de ${numPaginas}`,
            description: "",
            color: 0x00FFFF
          }
        });
        for (let i = 0 + pagina * 4; i < 4 + 4 * pagina; i++){
          let mangas_nomes = result.rows[i].fields.titulo;
        
          let mangas_capitulo = result.rows[i].fields.ultimo_cap;
        
          let mangas_status = result.rows[i].fields.status;
        
          let mangas_url = result.rows[i].fields.url;
        
          let mangas_favorito = result.rows[i].fields.favorito;
          
          await lib.discord.channels['@0.0.6'].messages.create({
            "channel_id": `${context.params.event.channel_id}`,
            "content": "",
            "tts": false,
            "components": [
              {
                "type": 1,
                "components": [
                  {
                    "style": 5,
                    "label": "Link",
                    "url": `${mangas_url}`,
                    "disabled": false,
                    "type": 2
                  }
                ]
              }
            ],
            "embed": {
              "type": "rich",
              "title": "",
              "description": "",
              "color": 0x00FFFF,
              "fields": [
                {
                  "name": `${mangas_nomes}`,
                  "value": `Capítulo ${mangas_capitulo}`
                }
              ],
              "footer": {
                "text": `Status: ${mangas_status}`
                }
            }
          }); // END MESSAGE.CREATE
        } // END FOR LOOP
        break;
      } // END CASE FAVORITOS
      
      case "Lendo": case "Completo": case "Pretendendo Ler":{

        let result = await lib.googlesheets.query['@0.3.0'].select({
          range: `A:F`,
          bounds: 'FIRST_EMPTY_ROW',
          where: [{'status__is': `${categoria}`}],
          limit: {
            'count': 0,
            'offset': 0
          }
        });
        
        let numItens = result.rows.length;
        let numPaginas = Math.ceil(numItens / 4);
        
        await lib.discord.channels['@0.0.6'].messages.create({
          channel_id: context.params.event.channel_id,
          content: "Aqui está sua lista:",
          tts: false,
          embed:{
            type: "rich",
            title: `Página ${pagina + 1} de ${numPaginas}`,
            description: "",
            color: 0x00FFFF
          }
        });

        for (let i = 0 + pagina * 4; i < 4 + 4 * pagina; i++){
          let mangas_nomes = result.rows[i].fields.titulo;
        
          let mangas_capitulo = result.rows[i].fields.ultimo_cap;
        
          let mangas_status = result.rows[i].fields.status;
        
          let mangas_url = result.rows[i].fields.url;
        
          let mangas_favorito = result.rows[i].fields.favorito;

          await lib.discord.channels['@0.0.6'].messages.create({
            "channel_id": `${context.params.event.channel_id}`,
            "content": "",
            "tts": false,
            "components": [
              {
                "type": 1,
                "components": [
                  {
                    "style": 5,
                    "label": "Link",
                    "url": `${mangas_url}`,
                    "disabled": false,
                    "type": 2
                  }
                ]
              }
            ],
            "embed": {
              "type": "rich",
              "title": "",
              "description": "",
              "color": 0x00FFFF,
              "fields": [
                {
                  "name": `${mangas_nomes}`,
                  "value": `Capítulo ${mangas_capitulo}`
                }
              ],
              "footer": {
                "text": `Status: ${mangas_status}`
                }
            }
          }); // END MESSAGE.CREATE
        } // END FOR LOOP
        break;
      } // END CASE LENDO | COMPLETO | PRETENDENDO LER
    } // END SWITCH
  } // END IF (pagina >= 0 && pagina < numPaginas)
} // END IF (providedOptionFields.length)