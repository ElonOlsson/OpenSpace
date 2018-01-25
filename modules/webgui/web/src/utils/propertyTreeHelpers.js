export const splitURI = (URI) => {
  const indexForName = URI.indexOf('.');
  const name = URI.substring(0, indexForName != -1 ?
    indexForName : URI.length);
  const newURI = URI.substring(indexForName + 1, URI.length);

  return {name: name, URI: newURI, lastOwner: newURI.indexOf('.') === -1, lastNode: URI.indexOf('.') === -1}
}

export const getIdOfProperty = (URI) => {
  const indexForName = URI.lastIndexOf('.');
  return URI.substring(indexForName != -1 ?
    indexForName + 1 : 0, URI.length);
}

//Function to return a deep copy of an object
export const keepCloning = (objectpassed) => {
  if (objectpassed === null || typeof objectpassed !== 'object') {
     return objectpassed;
  }
  // give temporary-storage the original obj's constructor
  var temporaryStorage = objectpassed.constructor();
  for (var key in objectpassed) {
    temporaryStorage[key] = keepCloning(objectpassed[key]);
  }
  return temporaryStorage;
}

const traverseTree = (node, URI) => {
  const splittedURI = splitURI(URI);
  let tmpValue;
  if (splittedURI.lastNode) {
    node.properties.forEach(function(element) {
      if(element.id === splittedURI.URI) {
        tmpValue = element;
      }
    })
    return tmpValue;
  }
  else {
    node.subowners.forEach(function(element) {
      if( element.name === splittedURI.name) {
        if(splittedURI.lastNode)
          tmpValue = element;
        else
          tmpValue = traverseTree(element, splittedURI.URI);
        return tmpValue;
      }
    })
    return tmpValue;
  }
}

export const findPropertyTreeNode = (state, URI) => {
  let property;
  const splittedURI = splitURI(URI);
  let returnNode;
  state.forEach(function(element) {
    if( element.name === splittedURI.name) {
      returnNode = traverseTree(element, splittedURI.URI);
    }
  })
  return returnNode;
}

//Conversion from json type array to lua
export const jsonToLuaTable = (json) => {
    return json.replace('[', '').replace(']', '');
}

export const jsonToLuaString = (json) => {
    return '"' + json + '"';
}

//Convert envelopes in transfer function property to back end compatible format
export const convertEnvelopes = (envelopes) => {
    var convertedEnvelopes = keepCloning(envelopes);
    convertedEnvelopes = convertedEnvelopes.map(envelope =>
      Object.assign({},
        {points: envelope.points.map(point =>
            Object.assign({},
            { color : point.color,
              position : point.position,
            })
          )
        },
      )
    )
    return JSON.stringify(convertedEnvelopes);
  }