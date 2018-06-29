// ligature.js v1.0
// http://code.google.com/p/ligature-js/
ligature = function(node) {
    if (!node) {
        ligature(document.body);
    }
    else {
        if (node.nodeType == 3 && !/^(SCRIPT|PRE|CODE)$/.test(node.parentNode.nodeName)) {
            node.nodeValue = node.nodeValue
                //.replace(/ffl/g, 'ﬄ')
                //.replace(/ffi/g, 'ﬃ')
                .replace(/fl/g, 'ﬂ')
                .replace(/fi/g, 'ﬁ');
                //.replace(/ff/g, 'ﬀ');
            if (node.childNodes) {
                for (var i=0; i < node.childNodes.length; i++) {
                    gature(node.childNodes.item(i));
                }
            }
        }
    }
};
