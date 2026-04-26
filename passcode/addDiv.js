function addsecretdiv(){
	const scdiv = document.getElementById('secretdiv');
	var newDiv = document.createElement('div');

	newDiv.innerHTML = '\
            <div class="bg-white rounded-2xl p-8 card-hover" id="secretpass">\
            	<h3>SecretText</h3>\
				<twisty-player alg="x2050 (R65 U65 R63 U63 R63 F65 B64 E64 D64 R66 L64 U63 R63 B64 M64 S64 U63 R65 U65 R63 M64 F63)2"></twisty-player>\
				<script src="https://cdn.cubing.net/v0/js/cubing/twisty" type="module"></script>\
            </div>';
	newDiv.setAttribute('id', 'newDiv');

	scdiv.appendChild(newDiv);
	document.getElementById('inputpass').remove();
}
