$(document).ready(function() {
	$(".wordnew").animate({'top': '+=30'}, 200);
	$("#infoButton").click(function() {
		$("#infoButton").animate({"right": "-=25"}, 500);
		$("#infoBox").animate({'right': '+=177'}, 500);
	});
	$(".ibCloseButton").click(function() {
		$("#infoButton").animate({"right": "+=25"}, 500);
		$("#infoBox").animate({"right": "-=177"}, 500);
	});
	$(".closeBox").click(function() {
		$("#infoButton").animate({"right": "+=25"}, 500);
		$("#infoBox").animate({"right": "-=177"}, 500);
	});
});
