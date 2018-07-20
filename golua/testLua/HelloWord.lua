function printmsg() 
	print("hello world") 
end 

function process_request(reqCtx)
    local uri_path = go.get_uri_path(reqCtx)
    print(uri_path)
    local count = go.write(reqCtx, uri_path)
    if count ~= string.len(uri_path) then
        print("write count is", count, "length of uri_path is", string.len(uri_path))
    end
end

function addFuncLua(first)
	print("2:lua call C == addFuncLua:value:" .. tostring(first))

	local result_table = go.cAddFuncGo("hanfeng")--.GetConfigInt("hanfeng")
	print("mydata1: " .. tostring(go.gamezone.Gameid))
	print("over ================== result:" .. tostring(result_table.GetConfigInt("hanfeng")))
end