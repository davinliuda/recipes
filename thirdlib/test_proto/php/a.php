<?php
	namespace ProtoCS;
	require "ProtoCS/Msg.php";
	require "ProtoCS/ModReq.php";

	$foo = new Msg();
	$foo->SetId(7);
	//$foo->setRetRetRet(11);
	
	$modreq = new ModReq();
	$modreq->setB(true);

	$foo->setModReq($modreq);

	$str = $foo->SerializeToString();
	echo bin2hex($str), "\n";
	
?>
