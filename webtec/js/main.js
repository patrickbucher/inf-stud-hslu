function loadPageIntoMain(pageName) {
	var src = getSourceByPageName(pageName);
	$.ajax({
		url : src,
		dataType : 'text/html',
		success : function(data) {
			$("section#main").html(data);
			if (pageName == 'text-pics') {
				loadImages();
				loadText();
			}
		},
		dataType : "text"
	});
}

function getSourceByPageName(pageName) {
	return 'pages/' + pageName + '.html';
}

function setStyle(styleName, setCookie) {
	$('body').removeClass();
	$('body').addClass(styleName);
	if (setCookie) {
		var expires = new Date();
		expires.setTime(expires.getTime() + (1000 * 3600 * 24 * 30)); // 30
		// days
		var cookieStr = 'style=' + styleName + '; expires='
				+ expires.toUTCString();
		document.cookie = cookieStr;
	}
}

function setStyleFromCookie() {
	var cookie = document.cookie;
	if (cookie.lastIndexOf('style=dark') != -1) {
		setStyle('dark', false);
	} else if (cookie.lastIndexOf('style=light') != -1) {
		setStyle('light', false);
	} else {
		// default: dark
		setStyle('dark', false);
	}
}

function loadText() {
	$('.textContainer').each(function() {
		var container = $(this);
		var id = container.attr('id');
		var src = 'data/' + id + '.html';
		container.load(src); // load text using AJAX
	});
}

/*
 * loads a file containing all the src and alt elements for the image tags that
 * need to be created
 */
function loadImages() {
	$.ajax({
		type : 'GET',
		dataType : 'json',
		url : 'data/images.json',
		success : function(data) {
			$.each(data["images"], function(i, v) {
				var image = $('<img src="' + v["src"] + '" alt="' + v["alt"]
						+ '" />');
				$('#' + v['id']).append(image);
			});
		},
		error : function(err, msg) {
			console.log('error loading images.json, cause: ' + msg);
		}
	});
}

function submitForm() {
	var nameEntered = $('#yourName').val().trim();
	var emailEntered = $('#yourEmail').val().trim();
	var complaintEntered = $('#yourComplaint').val().trim();
	var errorList = $('ul#formError');
	errorList.empty();
	var error = false;
	if (nameEntered == '') {
		errorList.append('<li>Bitte Geben Sie einen Namen an.</li>');
		error = true;
	}
	if (emailEntered == '') {
		errorList.append('<li>Bitte Geben Sie eine E-Mail-Adresse an.</li>');
		error = true;
	}
	if (complaintEntered == '') {
		errorList.append('<li>Bitte Geben Sie eine Anfrage ein.</li>');
		error = true;
	}
	if (error) {
		errorList.removeClass('hidden');
		return;
	}
	$("#nameFeedback").html(nameEntered);
	$("#emailFeedback").html(emailEntered);
	$("#complaintFeedback").html(complaintEntered);
	$("form").addClass('hidden');
	$("div#formFeedback").removeClass('hidden');
}

$(document).ready(function() {
	$('nav a').each(function() {
		var link = $(this);
		var pageName = link.attr('href').substr(1); // omit #
		link.click(function() {
			loadPageIntoMain(pageName);
		});
	});
	$('a.styleSwitcher').each(function() {
		var link = $(this);
		var styleName = link.attr('id');
		link.click(function(e) {
			e.preventDefault();
			setStyle(styleName, true);
		});
	});
	(function loadInitialPage() {
		var sharpPos = window.location.href.lastIndexOf('#');
		var pageName = 'home';
		if (sharpPos != -1) {
			pageName = window.location.href.substr(sharpPos + 1);
		}
		loadPageIntoMain(pageName);
		setStyleFromCookie();
	})();
});
