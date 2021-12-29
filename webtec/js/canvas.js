var requestId;

function getCanvas() {
	var canvasElement = $('#russianAnthemCanvas');
	return canvasElement[0];
}

function get2dContext(canvas) {
	return canvas.getContext('2d');
}

function getAttr(attr, canvas) {
	return $(canvas).attr(attr);
}

function drawCanvas() {
	var canvas = getCanvas();
	var height = getAttr('height', canvas);
	var width = getAttr('width', canvas);
	var context = get2dContext(canvas);
	
    var whiteToBlue = context.createLinearGradient(0, 0, 0, height / 2);
    whiteToBlue.addColorStop(0, 'white');
    whiteToBlue.addColorStop(1, 'blue');
    context.fillStyle=whiteToBlue;
    context.globalAlpha=0.35;
    context.fillRect(0, 0, width, height / 2);

    var blueToRed = context.createLinearGradient(0, height / 2, 0, height);
    blueToRed.addColorStop(0,'blue');
    blueToRed.addColorStop(1,'red');
    context.fillStyle = blueToRed;
    context.fillRect(0, height / 2, width, height / 2);

    context.globalAlpha = 1;

    var font_size = 16;
    context.font = font_size + 'px serif';
    context.fillStyle = '#0a0a0a';
    var y_margin = 6;
    var line_height = font_size + y_margin;
    var lines_ru = [
        'Россия — священная наша держава,',
        'Россия — любимая наша страна.',
        'Могучая воля, великая слава —',
        'Твоё достоянье на все времена!',
        '',
        'Славься, Отечество наше свободное,',
        'Братских народов союз вековой,',
        'Предками данная мудрость народная!',
        'Славься, страна! Мы гордимся тобой!',
        '',
        'От южных морей до полярного края',
        'Раскинулись наши леса и поля.',
        'Одна ты на свете! Одна ты такая —',
        'Хранимая Богом родная земля!',
        '',
        'Славься, Отечество наше свободное,',
        'Братских народов союз вековой,',
        'Предками данная мудрость народная!',
        'Славься, страна! Мы гордимся тобой!',
        '',
        'Широкий простор для мечты и для жизни',
        'Грядущие нам открывают года.',
        'Нам силу даёт наша верность Отчизне.',
        'Так было, так есть и так будет всегда!',
        '',
        'Славься, Отечество наше свободное,',
        'Братских народов союз вековой,',
        'Предками данная мудрость народная!',
        'Славься, страна! Мы гордимся тобой!',
    ];
    var y_coord = font_size + y_margin / 2;
    for (var i in lines_ru) {
        context.fillText(lines_ru[i], 5, y_coord);
        y_coord += line_height;
    }
    
    window.requestAnimationFrame(drawSnowflake);
}

function drawSnowflake() {
	var canvas = getCanvas();
	
	// when the page has been left
	if (canvas == null) {
		return;
	}
	var height = getAttr('height', canvas);
	var width = getAttr('width', canvas);
	var context = get2dContext(canvas);
	
	var w = 5,h = 5, y = 5;
	var x = Math.floor(Math.random() * (width - 2 * w) ) + 5 ;
	var y = Math.floor(Math.random() * (height - 2 * h) ) + 5 ;
	context.beginPath();
	context.fillStyle = "#ffffff";
	context.arc(x, y, 2, 0, Math.PI*2);
	context.fill();
	context.closePath();

	setTimeout(() => {
		window.requestAnimationFrame(drawSnowflake);
	}, 500);
}
