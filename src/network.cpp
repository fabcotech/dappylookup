
#include <string>
#include <map>
#include <vector>
#include <libbase64.h>

std::vector<std::map<std::string, std::string>> dNetwork = {
  {
    {"ip", "143.244.205.40"},
    {"port", "443"},
    {"hostname", "node1.d.fabco.dappy"},
    {"caCert", "LS0tLS1CRUdJTiBDRVJUSUZJQ0FURS0tLS0tDQpNSUlDOGpDQ0FkcWdBd0lCQWdJSkFMeEhmREMvOVEvSk1BMEdDU3FHU0liM0RRRUJDd1VBTUI0eEhEQWFCZ05WDQpCQU1NRTI1dlpHVXhMbVF1Wm1GaVkyOHVaR0Z3Y0hrd0hoY05Nakl3T1RJMk1UTXdOak0xV2hjTk16QXhNakV6DQpNVE13TmpNMVdqQWVNUnd3R2dZRFZRUUREQk51YjJSbE1TNWtMbVpoWW1OdkxtUmhjSEI1TUlJQklqQU5CZ2txDQpoa2lHOXcwQkFRRUZBQU9DQVE4QU1JSUJDZ0tDQVFFQWxVSmJmcEJGSWJsRWo2TEFIYlZWMWVLNWEwWVhFaVp0DQpTWFFIUUVIWnIzVllQR01iTU1pZFhJaFA0S3FFY0hMQy9NT0N6Vjd0VjVnOWRzNXNpMFdrRVdrVGU2b2tBa0FQDQpkMGhBUk9hc2ROVWdPL2FlYmtDQkVHNDVVVFo0WDQ0ZktraEFldkx5NHpBVmhiSmpyOGdGcGM3ZDN1ZFhINzhSDQprWG9sbWxzYmdzNDY5KzBNK01MUzVMKzRNVG5LajgwK1lpdDFyMTJ1TDlzYW9lalVHUndLOWh1LzUrTDI5Sm9FDQpVZk01SHBkNHZYM0tER0lDOUpRUmVzMllqYllnRDBIZkpUZmdGazRWUFdNRkhpdXVMYU5Lc2pld2tGbzZGc1RjDQozdHJlRUt2VEJWRlBwZjRUOWZET1RwYThYZWRFQlZDb09Pa2Z4cko4dWhmbmE1Y3lTMWVHWlFJREFRQUJvek13DQpNVEFQQmdOVkhSTUJBZjhFQlRBREFRSC9NQjRHQTFVZEVRUVhNQldDRTI1dlpHVXhMbVF1Wm1GaVkyOHVaR0Z3DQpjSGt3RFFZSktvWklodmNOQVFFTEJRQURnZ0VCQUlwek5oU1luU3hKTjlQUDZTTTNCK0ZhcVYvZzluMUUrdXZQDQora0RNQ2hBdjlvQnE5U1ZOZHFtUzM3Z1JJWDhSNVpidFBGeTdTQ1VVOUdia3pNUHJXNmdSY2ZZMkNQNzA1cktqDQpQQVBQeFBGeFVub0tjalBQL1ZOdk13MnoxYlBNQ2grckg5blNXcUdkTTlCQXBXOUdGbitTc2RTQUR3eWdJRUdvDQpjbDNBR1R1YnFFU0o0UW8reldzYnVFU1NyckQ3L0l6VHBKd3FycCt6cTVlM1Q3cURaK2tPQitBVmVDd05uKzVDDQp1ODlMS2hzREpWL3dwU2pva2oxWXZJcFQzQXVUTXUrUU1oZFRjMTNuODFNM3RVUFBlT3EzbXIrL29IbmJlaWx2DQp3ZmFFWnk4Vnk3R0NqbTNzK1kzeHFTRnEzRXFTckdLOGROTEdZSWtlaTNGRDh3Q1c2ZkU9DQotLS0tLUVORCBDRVJUSUZJQ0FURS0tLS0t"}
  },
  {
    {"ip", "95.111.244.128"},
    {"port", "443"},
    {"hostname", "node1.d.pathrock.dappy"},
    {"caCert", "LS0tLS1CRUdJTiBDRVJUSUZJQ0FURS0tLS0tCk1JSUM5VENDQWQyZ0F3SUJBZ0lVVXVXdWlLRytBZTJ5T3FMc2Y1MWszWStTbmk0d0RRWUpLb1pJaHZjTkFRRUwKQlFBd0lURWZNQjBHQTFVRUF3d1dibTlrWlRFdVpDNXdZWFJvY205amF5NWtZWEJ3ZVRBZUZ3MHlNakV3TVRNeApNREl6TkRKYUZ3MHpNREV5TXpBeE1ESXpOREphTUNFeEh6QWRCZ05WQkFNTUZtNXZaR1V4TG1RdWNHRjBhSEp2Clkyc3VaR0Z3Y0hrd2dnRWlNQTBHQ1NxR1NJYjNEUUVCQVFVQUE0SUJEd0F3Z2dFS0FvSUJBUURIWFB5MWdseEkKQVlOY2h3Vk81VEFuNWtLbkV3eDBvdGtsUHExamF2MC9aSGZDSGxEbkpabHk3Njd0Rk1WdG15ZjQ3bEY0WnNQQwoxWUx0KzdIcXdzNHN4M29IeGhXRzUxYXpsUm9YSXdaRVhRbzBGZGg3OTJsd0ZOcTF1dVBGUVh4UWV2L0t1VGZPCjFZalorUHgvOEtzeXZyMUNaM0xKc05ONVRBQ1hsTjBEUkkzZ0IxRHRsSThrbFN5Q2Z6YkFKbmprZnZrTHQ2THMKRWRmdyttSEdyWmpHK1EwbHhTVWJUWTM5TlV0eU1XbnFIZ0lMRlFDdUU1U0dXc3R5T0JwRTZvRWF5R3dKRFQwYQptOEFqUy9hTStEVC8rQkFheEs2ZlZWSEpHRFVQd1RobENTb01JTTE0UnlkQllJQWZZT2U0eVdSUC9TdzdiYTlICi9ybCtzRHMzM2JtTkFnTUJBQUdqSlRBak1DRUdBMVVkRVFRYU1CaUNGbTV2WkdVeExtUXVjR0YwYUhKdlkyc3UKWkdGd2NIa3dEUVlKS29aSWh2Y05BUUVMQlFBRGdnRUJBQnpSMEd3dzFUL2I4OGk0QlhLU2tkRmFXSnpkMkhRVgpYTG51TTVrZFhZRjQ0a0ZGRm4rQnFDd0JjM1FHN0FUMEsrei85amNUTVpaWEdWMThQTGNvai9ZTmFGY1hGeVcxCmxNL2pOUnM3YzBoT3hlUDk1dE8wU0gvL1hPaTBjWkJ0djJYYkZuUEtVYThOaUVsNHNQQkZFQ2Z4TFBkdzJkNUkKMTRlam4rRHZwRkROQUppSDBOU2w5UFV4QXlSSDZQcHhkY3dlNkdzZXBiZmdteVBXamgrN1cyUmNxaE5paUdPMQovc3lrWnpXUVVoenQzL0ZtNFpvcDlhdTRHRDFTM3RPOVBlaVkwMnhsL2JHT2o5UkxaRFhHcWJsN2tkRTN0bjlQClg1cUhoQlhFVC9yU2V6OThzcXh0ajlqNG00cnlucmRydVN2VzQ5cWwxRDc1bmg5OS9qTlpsWWs9Ci0tLS0tRU5EIENFUlRJRklDQVRFLS0tLS0="}
  },
};

std::vector<std::map<std::string, std::string>> gammaNetwork = {
  {
    {"ip", "143.244.205.40"},
    {"port", "443"},
    {"hostname", "node1.d.fabco.dappy"},
  },
  {
    {"ip", "95.111.244.128"},
    {"port", "443"},
    {"hostname", "node1.d.pathrock.dappy"},
  },
};

std::vector<std::map<std::string, std::string>> localNetwork = {
  {
    {"ip", "127.0.0.1"},
    {"port", "3002"},
    {"hostname", "localhost"},
    {"caCert", "LS0tLS1CRUdJTiBDRVJUSUZJQ0FURS0tLS0tDQpNSUlDempDQ0FiYWdBd0lCQWdJVWZnTXd1Um1raTVoTUVPaVlLOWY5U0J6SEFiRXdEUVlKS29aSWh2Y05BUUVMDQpCUUF3RkRFU01CQUdBMVVFQXd3SmJHOWpZV3hvYjNOME1CNFhEVEl5TURReU9EQTRORGN6TVZvWERUUXlNRFF5DQpNekE0TkRjek1Wb3dGREVTTUJBR0ExVUVBd3dKYkc5allXeG9iM04wTUlJQklqQU5CZ2txaGtpRzl3MEJBUUVGDQpBQU9DQVE4QU1JSUJDZ0tDQVFFQXJaa2pRWm04S3VObmpCY05IQW9NQTJQRGpMWG10dVE5V0hQcU8vUG8yQm1WDQpCSUNlT051K3N3UFJsNGRUeEJnNzhEQ21zLytIZHFVRzNmeGszd2xIOEx3Z1VCaXBWbVFvU3ptWlMwQ2wrYng4DQpRTHNNa2QzamxqVVp6QzJIYllQdHpDK29KMmVRQ2wzNlZDeENnWUY2Q1dsNkFkSytiT1ZJSjdheDRYZFdCUHFnDQpnNlFJWGMxUVgvZTdmNTcrMzJPSi85dlV1ZkNxblQySk1jQjMwMDlTUW5RQWZvV2hsQ2lwbk1yV1NoUnhDT1RoDQp0OEJsMXFkSWkxWnhRc0wrd1dQMjlFNXIxOEFyblpKdmx0S0c1ekZuenVCa2lVbG12cUxiNTU2VTg4aFdiQnRSDQo0ck4vWFpsTklZQkdqS2JaUmxrZUZldk1taG8zMXpwbUdiMDNicUhHN1FJREFRQUJveGd3RmpBVUJnTlZIUkVFDQpEVEFMZ2dsc2IyTmhiR2h2YzNRd0RRWUpLb1pJaHZjTkFRRUxCUUFEZ2dFQkFLMDQvTVFzMm51NWZTcmlwZUg0DQpDZ3V5ZS9qVEE1SG12VE9lT2lyaDlnNFhNdXdvM3BCSWJaNUZnbWhXV1B2b3NNSGZxWlpCRzFIbEJaeXBmT2lODQpkU09qOEduOE1kZ0Rmb1BHdFY1bVJTd0JyV0ppUElJTEtTMGFTZXBINU1BcVJHZnRKampzMWJxa3JaYlJlTkNkDQpTYkx2cFBzQXM5Q1VDSWZYeG96MlhtQlRxNnczWEtORnJNRVVCNmZjSEtLV21VM3BtMk9ZalBsSlZsNlFUaElPDQpDSzlqOGNLeHFDWERIZGo1bTczMXhsQlFwTWlKdCtreU1ZYk9QVmxKei9tcnM1Qkk1WVFSYTEvNEFFTU5GTi9tDQpSK3VlTVhDenczL2FYNmRXQlluRG0vcGwvaGh0V3ZZZUFTZ0Vhd0hZTWhxeUpPUnlUeDZJWERjUGdqL09COEhQDQpFWnc9DQotLS0tLUVORCBDRVJUSUZJQ0FURS0tLS0t"},
  }
};

std::vector<std::map<std::string, std::string>> getNetwork(std::string networkId) {
  for (int i = 0; i < dNetwork.size(); i++) {
    char cert_base64[dNetwork[i].at("caCert").length() + 1];
    strcpy(cert_base64, dNetwork[i].at("caCert").c_str()); 
    size_t cert_base64len = sizeof(cert_base64);
    char out3[cert_base64len];
    size_t out3len;
    base64_decode(cert_base64, cert_base64len, out3, &out3len, 0);
    // have to do this substr, if not there is a strange
    // last character after end of PEM -----
    std::string certificate_string = std::string(out3).substr(0, out3len);
    std::map<std::string, std::string>::iterator it = dNetwork[i].find("caCert");
    if (it != dNetwork[i].end())
      it->second = certificate_string;
  }

  for (int i = 0; i < localNetwork.size(); i++) {
    char cert_base64[localNetwork[i].at("caCert").length() + 1];
    strcpy(cert_base64, localNetwork[i].at("caCert").c_str()); 
    size_t cert_base64len = sizeof(cert_base64);
    char out3[cert_base64len];
    size_t out3len;
    base64_decode(cert_base64, cert_base64len, out3, &out3len, 0);
    // have to do this substr, if not there is a strange
    // last character after end of PEM -----
    std::string certificate_string = std::string(out3).substr(0, out3len);
    std::map<std::string, std::string>::iterator it = localNetwork[i].find("caCert");
    if (it != localNetwork[i].end())
      it->second = certificate_string;
  }


  if (networkId == "d") {
    return dNetwork;
  } else if (networkId == "gamma") {
    return gammaNetwork;
  } else if (networkId == "local") {
    return localNetwork;
  } else {
    throw std::string("unknown network id");
  }
}
