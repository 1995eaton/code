$(document).ready(
function() {
$(".wordnew").animate({'top': '+=30'}, 200);
});
var slideSpeed = 500;
$(document).ready(function() {
		$("#infoButton").click(function() {
			$("#infoButton").animate({"right": "-=25"}, slideSpeed);
			$("#infoBox").animate({'right': '+=177'}, slideSpeed);
			});
		$(".ibCloseButton").click(function() {
			$("#infoButton").animate({"right": "+=25"}, slideSpeed);
			$("#infoBox").animate({"right": "-=177"}, slideSpeed);
			});
		});
$(document).ready(function() {
		$(".closeBox").click(function() {
			$("#infoButton").animate({"right": "+=25"}, slideSpeed);
			$("#infoBox").animate({"right": "-=177"}, slideSpeed);
			});
		});
function idShow(id) {
document.getElementById(id).style.display = 'block';
}
function idClose(id) {
document.getElementById(id).style.display = "none";
}
