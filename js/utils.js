window.onload = function(e){
    function setType(e){
        let id = e.target.id;
        window.GEOMTYPE = id;
    }
    function setAdjust(e){
        let id = e.target.id;
        window.GEOMTYPEADJUST = id;
    }
    function setCoord(e){
        let id = e.target.id;
        window.COORDTYPE = id;
    }
    function makeButton(id, tag, className, text){
        tag = tag || "div"
        className = className || id; 
        let el = document.createElement("div");
        el.id = id;
        el.className = className;
        if( text ) el.innerHTML = text;
        return el;
    }
    
    let types = [
        "area", 
        "edge",
        "heatmap",
        "interval", 
        "line", 
        "path", 
        "point", 
        "polygon", 
        "schema", 
        "areaStack",
        "intervalDodge", 
        "intervalStack", 
        "intervalSymmetric", 
        "pointDodge", 
        "pointJitter", 
        "pointStack", 
        "schemaDodge"
    ];
    let adjust = ['stack', 'dodge', 'jitter', 'symmetric'];
    let coords = ['rect','polar','theta','gauge'];

    let toolbox = makeButton("toolbox");
    if(window.COORDTYPES) coords = COORDTYPES;
    if(window.GEOMTYPES) types = GEOMTYPES;
    if(window.GEOMADJUSTTYPES) adjust = GEOMADJUSTTYPES;
    for (var i = types.length - 1; i >= 0; i--) {
        var btn = makeButton(types[i], "div", "button", types[i]);
        btn.onclick = setType;
        toolbox.appendChild(btn);
    }
    for (var i = adjust.length - 1; i >= 0; i--) {
        var btn = makeButton(adjust[i], "div", "button", adjust[i]);
        btn.onclick = setAdjust;
        toolbox.appendChild(btn);
    }
    for (var i = coords.length - 1; i >= 0; i--) {
        var btn = makeButton(coords[i], "div", "button", coords[i]);
        btn.onclick = setCoord;
        toolbox.appendChild(btn);
    }
    document.body.appendChild(toolbox);
    // console.log(e,toolbox);
}